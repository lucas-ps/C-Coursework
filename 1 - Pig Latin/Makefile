CC = gcc

CFLAGS = -Wall -Wextra -Wpedantic -g
LIBS = 

all: piglatin test_pig

piglatin: piglatin.o pig.o
	gcc piglatin.c -o piglatin $(LIBS)

test_pig: test_pig.o pig.o
	gcc test_pig.c -o test_pig $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f piglatin test_pig *.o