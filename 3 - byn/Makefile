CC = gcc
CFLAGS = -g -std=c99
LIBS = -lgsl -lgslcblas -lm 

# This was necessary to get gsl working on macOS but may not be necessary for other platforms.
INCLUDES = # -I/opt/homebrew/include -L/opt/homebrew/lib

all: single byn

single: single.o shuffle.o beggar.o
	gcc $(CFLAGS) single.c -o single $(LIBS) $(INCLUDES)

byn: byn.o shuffle.o beggar.o
	gcc $(CFLAGS) byn.c -o byn $(LIBS) $(INCLUDES)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

clean:
	rm -f single shuffle byn *.o