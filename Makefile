CC=gcc
CCOPTS=-Wall -Wextra -Werror
LIBS=libvvsfs.a

SRCS=$(wildcard *.o)
TARGETS=$(SRCS:.c=)

.PHONY: clean pristine test

test: testfs

testfs: testfs.c libvvsfs.a
	$(CC) $(CCOPTS) -o $@ $< $(LIBS)

libvvsfs.a: block.o image.o
	ar rcs $@ $^

block.o: block.c
	$(CC) $(CCOPTS) -c $^

image.o: image.c
	$(CC) $(CCOPTS) -c $^

clean:
	rm -f $(TARGETS)
pristine: clean
	rm -f libvvsfs.a testfs