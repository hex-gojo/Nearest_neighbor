int nearest_neighbor_axim(volatile int fd) {

    char *nn_base, *virt_addr;
    volatile unsigned char tmp_data;
    int i = 0;

    /* nn frame buffer */
    nn_base = (char *)mmap(0, 0x32, PROT_READ | PROT_WRITE, MAP_SHARED, fd, NN_AXI_ADDR);
    if(gaus_base < 0){
        fprintf(stderr, "gaus_base mapped error\n");
    }

    /* set cam_fb_offset and nn_fb_offset */
    virt_addr = nn_base + XGAUS_FILTER_AXIM_AXILITES_ADDR_CAM_FB_OFFSET_DATA;
    *((unsigned int *) virt_addr) = IMG_FB_ADDR;
    virt_addr = nn_base + XGAUS_FILTER_AXIM_AXILITES_ADDR_GAUS_FB_OFFSET_DATA;
    *((unsigned int *) virt_addr) = NN_FB_ADDR;

    /* start nn */
    printf("\n=== start nearst neighbor hard ===\n");
    virt_addr = nn_base;
    tmp_data = *((unsigned char *) virt_addr);

    /* -------------------- debug -------------------- */
    printf("tmp_data : control = 0x%x\n", tmp_data);
    printf("before : control = 0x%x\n", *((unsigned char *) virt_addr));
    usleep(500000);
    /* ----------------------------------------------- */

    *((unsigned char *) virt_addr) = tmp_data | 0x1;

    /* -------------------- debug -------------------- */
    printf("after  : control = 0x%x\n", *((unsigned char *) virt_addr));
    /* ----------------------------------------------- */
    
    while((*((unsigned char *) virt_addr) & 0x2) != 0x2 ){
        tmp_data = *((unsigned char *) virt_addr);
        i++;
    }
    
    /* -------------------- debug -------------------- */
    printf("program end = 0x%x(%d)\n", *((unsigned char *) virt_addr), i);
    /* ----------------------------------------------- */
    
    *((unsigned char *) virt_addr) = *((unsigned char *) virt_addr) | 0x0;
    return 0;
}
