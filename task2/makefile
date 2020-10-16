all: fib_serial fib_openmp
fib_serial: fibonacci_serial.c
	gcc -fopenmp fibonacci_serial.c -o fib_serial
fib_openmp: fibonacci_openmp.c
	gcc -fopenmp fibonacci_openmp.c -o fib_openmp
# pi2: pi2.c
# 	gcc -fopenmp pi2.c -o pi2

clean:
	rm fib_serial fib_openmp

run:
	echo '45\n' | ./fib_serial
	echo '45\n' | ./fib_openmp