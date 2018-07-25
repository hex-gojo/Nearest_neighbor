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


#include "xgaus_filter_axim_hw.h"


using namespace cv;


#define DEV_FB "/dev/fb0"
#define HDMI_FB_ADDR 0x1fc00000
#define CAMERA_FB_ADDR 0x1F700000
#define NN_AXI_ADDR 0x43c40000
#define NN_FB_ADDR 0x1ff00000
#define IMG_FB_ADDR 0x20000000


#define VBPP 4 /* vinfo bits per pixel */
#define CVBPP 3


#define WIDTH_MAX  1280
#define HEIGHT_MAX 720


#define BEFORE_WIDTH  64
#define BEFORE_HEIGHT 64


#define AFTER_WIDTH  128
#define AFTER_HEIGHT 128


#define FIRST_X (WIDTH_MAX/2 - BEFORE_WIDTH/2)
#define FIRST_Y (HEIGHT_MAX/2 - BEFORE_HEIGHT/2)


#define FIRST ((FIRST_Y * WIDTH_MAX +FIRST_X) * VBPP)
#define INCV ((WIDTH_MAX - WIDTH) * VBPP)


typedef unsigned int u32;
typedef unsigned char u8;


void sigcatch(int sig) {
  printf("catch signal %dn", sig);
  exit(1);
}


int main(void){

  int i,j;
  int fd;
  int fb;
  int screensize = WIDTH_MAX * HEIGHT_MAX * VBPP;
  int imgsize = WIDTH * HEIGHT * VBPP;
  int time_flag = 0;

  u8 *camptr, *cam_base;
  u8 *hdmiptr, *hdmi_base;
  u8 *Matptr, *swMatptr, *hwMatptr;
  // u8 swinimg[imgsize] = {0}, *pswinimg;
  // u8 swoutimg[imgsize] = {0}, *pswoutimg;
  // u8 hwinimg[imgsize] = {0}, *phwinimg;
  // u8 hwoutimg[imgsize] = {0}, *phwoutimg;
  // u8 *phwoutimg;
  u8 *hw_nn_ptr, *hw_nn;
  u8 *in_img_hw_ptr, *in_img_hw;
  
  volatile u8 *gaus_base;
  volatile u32 *cam_offset_addr, *gaus_offset_addr;

  clock_t start, end;

  Mat intmp(Size(WIDTH, HEIGHT), CV_8UC3, Scalar::all(0));
  Mat out(Size(WIDTH, HEIGHT), CV_8UC3, Scalar::all(0));
  // Mat swtmp(Size(WIDTH, HEIGHT), CV_8UC3, Scalar::all(0));
  // Mat swout(Size(WIDTH, HEIGHT), CV_8UC3, Scalar::all(0));
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

  hw_nn = (u8 *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, GAUS_FB_ADDR);
  if(hw_gausd < 0){
    fprintf(stderr, "Can't allocate hw_lapd memory\n");
    exit(1);
  }

  in_img_hw = (u8 *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, IMG_FB_ADDR);
  if(in_img_hw < 0){
    fprintf(stderr, "Can't allocate in_img_hw memory\n");
    exit(1);
  }