#include "image.h"
#include "block.h"
#include "ctest.h"

#ifdef CTEST_ENABLE

void test_image_open(void){
    CTEST_ASSERT(image_fd==-1, "testing initialization of image_fd");
    CTEST_ASSERT(image_open("image.txt",0)>=0, "testing image_open");
}

void test_image_close(void){
    CTEST_ASSERT(image_close()==0, "testing image_close");
}

void test_bread(void){

}

void test_bwrite(void){

}

int main(){
    CTEST_VERBOSE(1);

    test_image_open();

    test_bread();

    test_bwrite();

    test_image_close();

    CTEST_RESULTS();

    CTEST_EXIT();
}

#else

int main(){
    image_open("image.txt",0);
    image_close();
}

#endif