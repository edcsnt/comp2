CC=gcc
CFLAGS=-static -Wall

all:
	$(CC) $(CFLAGS) -o comp2 comp2.c
check:
	$(CC) $(CFLAGS) -o comp2 comp2.c
	-./comp2
	-./comp2 foo
	rm comp2
clean:
	rm -f comp2
