CC=gcc
CFLAGS=-Wall -g

all: ex1 ex3 ex4 ex5 ex6 ex7

ex1: ex1.c
	$(CC) $(CFLAGS) ex1.c -o ex1

ex3: ex3.c
	$(CC) $(CFLAGS) ex3.c -o ex3

ex4: ex4.c
	$(CC) $(CFLAGS) ex4.c -o ex4

ex5: ex5.c
	$(CC) $(CFLAGS) ex5.c -o ex5

ex6: ex6.c
	$(CC) $(CFLAGS) ex6.c -o ex6

ex7: ex7.c
	$(CC) $(CFLAGS) ex7.c -o ex7

clean:
	rm -f ex1 ex3 ex4 ex5 ex6 ex7
