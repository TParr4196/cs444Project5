#ifndef BLOCK_H
#define BLOCK_H

const int BLOCK_SIZE;
unsigned char *bread(int block_num, unsigned char *block);
void bwrite(int block_num, unsigned char *block);

#endif