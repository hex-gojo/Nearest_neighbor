#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <signal.h>
#include <stdint.h>
#include <iostream>
#include <iomanip>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <time.h>

using namespace cv;

#include "main.h"
#include "xnearest_neighbor_axim_hw.h"

void sigcatch(int sig) {
  printf("catch signal %dn", sig);
  exit(1);
}


int main(void){

  int i,j;
  int fd;
  int fb;
  int screensize = WIDTH_MAX * HEIGHT_MAX * VBPP;
  int before_imgsize = BEFORE_WIDTH * BEFORE_HEIGHT * VBPP;
  int after_imgsize = AFTER_WIDTH * AFTER_HEIGHT * VBPP;
  int time_flag = 0;

  u8 *camptr, *cam_base;
  u8 *hdmiptr, *hdmi_base;
  u8 *Matptr, *swMatptr, *hwMatptr;
  u8 *hw_nn_ptr, *hw_nn;
  u8 *in_img_hw_ptr, *in_img_hw;
  
  volatile u8 *nn_base;
  volatile u32 *cam_offset_addr, *nn_offset_addr;

  clock_t start, end;

  Mat intmp(Size(WIDTH, HEIGHT), CV_8UC3, Scalar::all(0));
  Mat out(Size(WIDTH, HEIGHT), CV_8UC3, Scalar::all(0));
  Mat hwtmp(Size(WIDTH, HEIGHT), CV_8UC3, Scalar::all(0));
  Mat hwout(Size(WIDTH, HEIGHT), CV_8UC3, Scalar::all(0));


  /* /dev/mem open */
  if (signal(SIGHUP, sigcatch) == SIG_ERR) {
    munmap(cam_base, screensize);
    return 0;
  }

  /* Map camera frame buffer */
  cam_base = (u8 *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, CAMERA_FB_ADDR);
  if(cam_base < 0) {
    fprintf(stderr, "cam_base mapped error\n");
  }

  /* Map HDMI frame buffer */
//  hdmi_base = (u8 *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, HDMI_FB_ADDR);
//  if(hdmi_base < 0){
//    fprintf(stderr, "hdmi_base mapped error\n");
//  }

  hw_nn = (u8 *)mmap(0, after_imgsize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, NN_FB_ADDR);
  if(hw_nn < 0){
    fprintf(stderr, "Can't allocate hw_nn memory\n");
    exit(1);
  }

  in_img_hw = (u8 *)mmap(0, before_imgsize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, IMG_FB_ADDR);
  if(in_img_hw < 0){
    fprintf(stderr, "Can't allocate in_img_hw memory\n");
    exit(1);
  }

  /* Image window create */
  cvNamedWindow( "input", 1 );
  cvNamedWindow( "output-hw-", 1 );


  while (1) {
    camptr = cam_base + FIRST;
    Matptr = intmp.data;
    
    /* hardware */
    hwMatptr = hwtmp.data;
    in_img_hw_ptr = in_img_hw;
    hw_nn_ptr = hw_nn;

    /* write picsel data */
    for(i = 0; i < HEIGHT; i++){
      for(j = 0; j < WIDTH; j++){
        memcpy(Matptr, camptr, CVBPP);
        memcpy(in_img_hw_ptr + 1, camptr, CVBPP);
        camptr += VBPP;
        Matptr += CVBPP;
        in_img_hw_ptr += VBPP;
      }
      camptr += INCV;
    }

    /* hw-gaussian */
    start = clock();
    nearest_neighbor_axim(fd);
    end = clock();
    if(time_flag == 0){
      printf("hw_gaus : %.2fms\n",(double)(end - start)/CLOCKS_PER_SEC*1000);
      time_flag = 1;
    }

    /* array2Mat */
    for(i = 0; i < HEIGHT; i++){
      for(j = 0; j < WIDTH; j++){
        memcpy(hwMatptr, hw_nn_ptr + 1, CVBPP);
        hw_nn_ptr += VBPP;
        hwMatptr += CVBPP;
      }
    }

    /* RGB2BGR */
    cvtColor(intmp, out, CV_RGB2BGR);
    cvtColor(hwtmp, hwout, CV_RGB2BGR);

    /* show Image */
    imshow("input", out);
    imshow("output-hw-", hwout);

    if(waitKey(10) == 'q')
      goto _cleanup_;
  }

  printf("\n=== stop program ===\n")
  waitKey(0);


_cleanup_:
  printf("---Start cleanup---\n");

  cvDestroyWindow("input");
  cvDestroyWindow("output-hw-");

  if(munmap(cam_base, screensize)==-1) {
    fprintf(stderr, "cam_base unmap error\n");
  }
  if(munmap(hw_nn, screensize) == -1){
    fprintf(stderr, "hw_nn unmap error\n");
  }
  if(munmap(in_img_hw, screensize) == -1){
    fprintf(stderr, "in_img_hw unmap error\n");
  }
  close(fd);

  printf("---All clear---\n");
  return 0;
}