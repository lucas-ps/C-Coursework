CC = gcc

CFLAGS = -g -std=c99 -lrt
LIBS = 

all: quality demo_shuffle

quality: quality.o riffle.o
	gcc $(CFLAGS) quality.c -o quality $(LIBS)

demo_shuffle: demo_shuffle.o riffle.o
	gcc $(CFLAGS) demo_shuffle.c -o demo_shuffle $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f quality demo_shuffle *.o