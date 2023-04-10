CC = gcc

CFLAGS = -g -std=gnu99
LIBS = 

all: piglatin test_pig

piglatin: piglatin.o pig.o
	gcc $(CFLAGS) piglatin.c -o piglatin $(LIBS)

test_pig: test_pig.o pig.o
	gcc $(CFLAGS) test_pig.c -o test_pig $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f piglatin test_pig *.o