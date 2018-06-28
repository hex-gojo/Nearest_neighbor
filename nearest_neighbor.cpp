#define BEFORE_WIDTH 64
#define BEFORE_HEIGHT 64

#define AFTER_WIDTH 128
#define AFTER_HEIGHT 128

#define SCALE 2

typedef unsigned char u8;
typedef unsigned int u32;

int nearest_neighbor_axim(volatile u32 *cam_fb, volatile u32 *nn_fb){

	for(int y = 0; y < AFTER_HEIGHT; y++){
		for(int x = 0; x < AFTER_WIDTH; x++){
			int xp = (int)(x/SCALE);
			int yp = (int)(y/SCALE);

			if(xp < BEFORE_WIDTH && yp < BEFORE_HEIGHT){
				nn_fb[y*AFTER_WIDTH+x] = cam_fb[yp*BEFORE_WIDTH+xp];
			}
		}
	}
	return 0;
}
