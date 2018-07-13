#define BEFORE_WIDTH 64
#define BEFORE_HEIGHT 64

#define AFTER_WIDTH 128
#define AFTER_HEIGHT 128

#define BEFORE_ALL_PIXEL_VALUE (BEFORE_WIDTH*BEFORE_HEIGHT)
#define AFTER_ALL_PIXEL_VALUE (AFTER_WIDTH*AFTER_HEIGHT)

#define SCALE 2

int nearest_neighbor_axim(volatile unsigned int *cam_fb, volatile unsigned int *nn_fb){

#pragma HLS INTERFACE s_axilite port=return
#pragma HLS INTERFACE m_axi depth=16384 port=nn_fb offset=slave bundle=nn_fb
#pragma HLS INTERFACE m_axi depth=4096 port=cam_fb offset=slave bundle=cam_fb

	int y, x, xp, yp;
	for(y = 0; y < AFTER_HEIGHT; y++){
		for(x = 0; x < AFTER_WIDTH; x++){
			xp = (int)(x/SCALE);
			yp = (int)(y/SCALE);

			if(xp < BEFORE_WIDTH && yp < BEFORE_HEIGHT){
				nn_fb[y*AFTER_WIDTH+x] = cam_fb[yp*BEFORE_WIDTH+xp];
			}
		}
	}
	return 0;
}
