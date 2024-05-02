#include "block.h"
#include "image.h"
#include <stdio.h>
#include <unistd.h>

const int BLOCK_SIZE = 4096;

unsigned char *bread(int block_num, unsigned char *block){
    int chk=lseek(image_fd, block_num*BLOCK_SIZE, SEEK_SET);
    if(chk<0){
        fprintf(stderr, "lseek failed");
    }
    chk=write(image_fd, block, BLOCK_SIZE);
    if(chk<0){
        fprintf(stderr, "write failed");
    }
    return block;
}

void bwrite(int block_num, unsigned char *block){
    int chk=lseek(image_fd, block_num*BLOCK_SIZE, SEEK_SET);
    if(chk<0){
        fprintf(stderr, "lseek failed");
    }
    chk=read(image_fd, block, BLOCK_SIZE);
    if(chk<0){
        fprintf(stderr, "write failed");
    }
}