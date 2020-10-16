all: dot_serial dot_openmp
dot_serial: dot_serial.c
	gcc -fopenmp dot_serial.c -o dot_serial
dot_openmp: dot_openmp.c
	gcc -fopenmp dot_openmp.c -o dot_openmp
clean:
	rm dot_serial dot_openmp