CC=gcc
CFLAGS=-Wall -g

all: ex1 ex3 ex4 ex5 ex6 ex7 ex8 ex9 ex10 ex11 ex12 ex13 ex14 ex15 ex16 ex16_b ex17 ex17_b

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

ex8: ex8.c
	$(CC) $(CFLAGS) ex8.c -o ex8

ex9: ex9.c
	$(CC) $(CFLAGS) ex9.c -o ex9

ex10: ex10.c
	$(CC) $(CFLAGS) ex10.c -o ex10

ex11: ex11.c
	$(CC) $(CFLAGS) ex11.c -o ex11

ex12: ex12.c
	$(CC) $(CFLAGS) ex12.c -o ex12

ex13: ex13.c
	$(CC) $(CFLAGS) ex13.c -o ex13

ex14: ex14.c
	$(CC) $(CFLAGS) ex14.c -o ex14

ex15: ex15.c
	$(CC) $(CFLAGS) ex15.c -o ex15

ex16: ex16.c
	$(CC) $(CFLAGS) ex16.c -o ex16

ex16_b: ex16_b.c
	$(CC) $(CFLAGS) ex16_b.c -o ex16_b

ex17: ex17.c
	$(CC) $(CFLAGS) ex17.c -o ex17

ex17_b: ex17_b.c
	$(CC) $(CFLAGS) ex17_b.c -o ex17_b

clean:
	rm -f ex1 ex3 ex4 ex5 ex6 ex7 ex8 ex9 ex10 ex11 ex12 ex13 ex14 ex15 
	rm -f ex16 ex16_b ex17 ex17_b
