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