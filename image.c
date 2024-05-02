#include "image.h"
#include <fcntl.h>
#include <unistd.h>

extern int image_fd;

int image_open(char *filename, int truncate){
    if(truncate){
        return open(filename, O_RDWR|O_CREAT|O_TRUNC, 0600);
    }
    else{
        return open(filename, O_RDWR|O_CREAT, 0600);
    }
}
int image_close(void){
    return close(image_fd);
}