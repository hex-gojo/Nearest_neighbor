#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#include "bmp_header.h"

#define AFTER_WIDTH 128
#define AFTER_HEIGHT 128

#define SCALE 2

int nearest_neighbor_axim(volatile unsigned int *cam_fb, volatile unsigned int *nn_fb);
void nn_soft(int *cam_fb, int *nn_fb, long width, long height);

int main(){
	int  *s, *h;
	long x, y;
	int i, j;
	BITMAPFILEHEADER bmpfhr; // BMP�t�@�C���̃t�@�C���w�b�_(for Read)
	BITMAPINFOHEADER bmpihr; // BMP�t�@�C����INFO�w�b�_(for Read)
	FILE *fbmpr, *fbmpw;
	int *rd_bmp, *hw_nn, *sw_nn;
	int blue, green, red;

	// Open test.bmp
	if ((fbmpr = fopen("test.bmp", "rb")) == NULL){
		fprintf(stderr, "Can't open test.bmp by binary read mode\n");
		exit(1);
	}

	// bmp�w�b�_�̓ǂݏo��
	fread(&bmpfhr.bfType, sizeof(uint16_t), 1, fbmpr);
	fread(&bmpfhr.bfSize, sizeof(uint32_t), 1, fbmpr);
	fread(&bmpfhr.bfReserved1, sizeof(uint16_t), 1, fbmpr);
	fread(&bmpfhr.bfReserved2, sizeof(uint16_t), 1, fbmpr);
	fread(&bmpfhr.bfOffBits, sizeof(uint32_t), 1, fbmpr);
	fread(&bmpihr, sizeof(BITMAPINFOHEADER), 1, fbmpr);

	// �s�N�Z�������郁�������A���P�[�g����
	if ((rd_bmp =(int *)malloc(sizeof(int) * (bmpihr.biWidth * bmpihr.biHeight))) == NULL){
		fprintf(stderr, "Can't allocate rd_bmp memory\n");
		exit(1);
	}
	if ((hw_nn =(int *)malloc(sizeof(int) * (AFTER_WIDTH * AFTER_HEIGHT))) == NULL){
		fprintf(stderr, "Can't allocate hw_nn memory\n");
		exit(1);
	}
	if ((sw_nn =(int *)malloc(sizeof(int) * (AFTER_WIDTH * AFTER_HEIGHT))) == NULL){
		fprintf(stderr, "Can't allocate sw_nn memory\n");
		exit(1);
	}

	// rd_bmp ��BMP�̃s�N�Z�������B���̍ۂɁA�s���t�]����K�v������
	for (y=0; y<bmpihr.biHeight; y++){
		for (x=0; x<bmpihr.biWidth; x++){
			blue = fgetc(fbmpr);
			green = fgetc(fbmpr);
			red = fgetc(fbmpr);
			rd_bmp[((bmpihr.biHeight-1)-y)*bmpihr.biWidth+x] = (blue & 0xff) | ((green & 0xff)<<8) | ((red & 0xff)<<16);
		}
	}
	fclose(fbmpr);

	// �n�[�h�E�F�A
	nearest_neighbor_axim((volatile unsigned int *)rd_bmp, (volatile unsigned int *)hw_nn);
	// �\�t�g�E�F�A
	nn_soft((int *)rd_bmp, (int *)sw_nn, bmpihr.biWidth, bmpihr.biHeight);

	// �n�[�h�E�F�A�ƃ\�t�g�E�F�A�̒l�̃`�F�b�N
	for(i=0, h=hw_nn, s=sw_nn; i<AFTER_HEIGHT; i++){
		for (j=0; j<AFTER_WIDTH; j++){
			if (*h != *s){
				printf("ERROR HW and SW results mismatch x = %ld, y = %ld, HW = %d, SW = %d\n", x, y, *h, *s);
				return(1);
			}else{
				h++;
				s++;
			}
		}
	}
	printf("Success HW and SW results match\n");

	// �n�[�h�E�F�A�̌��ʂ� result.bmp �֏o��
	if ((fbmpw=fopen("result.bmp", "wb")) == NULL){
		fprintf(stderr, "Can't open result.bmp by binary write mode\n");
		exit(1);
	}

	// BMP�t�@�C���w�b�_�̏�������
	fwrite(&bmpfhr.bfType, sizeof(uint16_t), 1, fbmpw);
	fwrite(&bmpfhr.bfSize, sizeof(uint32_t), 1, fbmpw);
	fwrite(&bmpfhr.bfReserved1, sizeof(uint16_t), 1, fbmpw);
	fwrite(&bmpfhr.bfReserved2, sizeof(uint16_t), 1, fbmpw);
	fwrite(&bmpfhr.bfOffBits, sizeof(uint32_t), 1, fbmpw);
	fwrite(&bmpihr, sizeof(BITMAPINFOHEADER), 1, fbmpw);

	// RGB �f�[�^�̏������݁A�t���ɂ���
	for (i=0; i<AFTER_HEIGHT; i++){
		for (j=0; j<AFTER_WIDTH; j++){
			blue = hw_nn[((AFTER_HEIGHT-1)-i)*AFTER_WIDTH+j] & 0xff;
			green = (hw_nn[((AFTER_HEIGHT-1)-i)*AFTER_WIDTH+j] >> 8) & 0xff;
			red = (hw_nn[((AFTER_HEIGHT-1)-i)*AFTER_WIDTH+j] >> 16) & 0xff;

			fputc(blue, fbmpw);
			fputc(green, fbmpw);
			fputc(red, fbmpw);
		}
	}
	fclose(fbmpw);
	free(rd_bmp);
	free(hw_nn);
	free(sw_nn);

	return(0);
}


void nn_soft(int *cam_fb, int *nn_fb, long width, long height){
	int y, x, xp, yp;
	for(y = 0; y < AFTER_HEIGHT; y++){
		for(x = 0; x < AFTER_WIDTH; x++){
			xp = (int)(x/SCALE);
			yp = (int)(y/SCALE);

			if(xp < width && yp < height){
				nn_fb[y*AFTER_WIDTH+x] = cam_fb[yp*width+xp];
			}
		}
	}
}
