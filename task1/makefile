all: pi0 pi1 pi2
pi0: pi0.c
	gcc -fopenmp pi0.c -o pi0
pi1: pi1.c
	gcc -fopenmp pi1.c -o pi1
pi2: pi2.c
	gcc -fopenmp pi2.c -o pi2

clean:
	rm pi0 pi1 pi2

run:
	./pi0 10000000
	./pi1 10000000
	./pi2 10000000