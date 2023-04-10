
# C Coursework

This is the coursework for my C module at the University of Exeter. The coursework consisted of 3 tasks - a Pig latin translator, A riffle shuffle program to shuffle a deck of cards and a "Beggar-your-neighbour" card game.

### Pig latin
A simple pig latin translator. ```piglatin.c``` allows you to enter your own string of words to be translated (up to 50 characters), and ```test_pig.c``` demonstrates the translator on sevaral different strings.

### Shuffle
Implements a riffle shuffle algorithm on an array. A riffle shuffle is a card shuffling technique where a deck is split into two halves and interwoven to create randomness. ```demo_shuffle.c``` demonstrates the shuffle on pre defined arrays, and ```quality.c``` evaluates the quality of a shuffle. For some reason, from my testing I got lower quality scores on linux (~0.38) than on macOS (~0.45). A perfect shuffle would have a score of ~0.5.

### Beggar-Your-Neighbour
The card game Beggar-Your-Neighbor uses a normal 52-card deck. An equal number of face-down cards are dealt to each player. They each turn over their top card and place it face up. If a Jack, Queen, King, or Ace is played as a punishment, the player after them must pay a fine by laying down additional cards in the following order: 1 for a Jack, 2 for a Queen, 3 for a King, and 4 for an Ace. The onus shifts to the following player if the player who was penalised plays another penalty card. The player who initially played the penalty card gathers all of the cards in the pile and places them at the bottom of their stack when the penalty is paid without playing a penalty card. When a player no longer has any cards, they are eliminated. 

```single.c``` prints out the details of a single game, ```byn.c``` prints out the statistics of a given number of games with a given number of players.




## Usage

To compile the C files, open a terminal in their directory then run ```make all```, then run ./program. You can then run ```make clean``` to get rid of the compiled files.
```
$ make all
gcc -g -std=c99 -c -o single.o single.c
gcc -g -std=c99 -c -o shuffle.o shuffle.c
gcc -g -std=c99 -c -o beggar.o beggar.c
gcc -g -std=c99 single.c -o single -lgsl -lgslcblas -lm
gcc -g -std=c99 -c -o byn.o byn.c
gcc -g -std=c99 byn.c -o byn -lgsl -lgslcblas -lm
$ ./byn
Shortest: 47
Longest: 739
Average: 207.00
$ make clean
rm -f single shuffle byn *.o
```


## Requirements

This project uses GSL, and and GNU99. Both of these should come installed with a GCC installation.
## License

[MIT](https://choosealicense.com/licenses/mit/)

