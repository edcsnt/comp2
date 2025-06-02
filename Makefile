CC=gcc
CFLAGS=-static -Wall

all:
	$(CC) $(CFLAGS) -o comp2 comp2.c
clean:
	rm -f comp2
