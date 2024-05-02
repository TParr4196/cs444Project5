CC=gcc
CCOPTS=-Wall -Wextra -Werror
LIBS=libvvsfs.a

SRCS=$(wildcard *.o)
TARGETS=$(SRCS:.c=)

.PHONY: clean pristine

testfs: testfs.c libvvsfs.a
	$(CC) $(CCOPTS) -o $@ $< $(LIBS)

libvvsfs.a: block.o image.o
	ar rcs $@ $^

clean:
	rm -f $(TARGETS)
pristine: clean
	rm -f libvvsfs.a testfs