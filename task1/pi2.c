/*=======================================================================*/
/* Approximates pi with the n-point quadrature rule 4 / (1+x**2)         */
/* applied to the integral of x from 0 to 1.                             */
/*=======================================================================*/
#include <stdio.h> 
#include <stdlib.h> 
#include <omp.h>
#include <time.h>

const double M_pi = 3.14159265358979323846; /* reference value */

double calc_pi(unsigned n)
{
    double h = 1.0 / n;
    double sum = 0.0;
    double x;
    int i;
    omp_set_num_threads(2);
    /* 
    Perform the code in an OpenMP parallel region for loop with a shared sum 
    */
    // #pragma omp parallel for reduction(+:sum)
    #pragma omp parallel for shared(sum)
    for (i = 0; i < n; i++)
    {
        x = (i + 0.5) * h;
        #pragma omp critical
        sum += 4.0 / (1.0 + x * x);
    }
    return h * sum;
}
int main(int argc, char *argv[])
{
    double time_spent = 0.0;
    clock_t begin = clock(); // start time of execution    

    int n;
    if (argc != 2)
    {
        fprintf(stderr, "usage: pi <num_iterations>\n");
        return 1;
    }
    n = atoi(argv[1]);
    if (n > 0)
    {
        double pi = calc_pi(n);
        double err = pi - M_pi;
        printf("Calculated pi is %19.15f\n", pi);
        printf("Referenced pi is %19.15f\n", M_pi);
        printf("  Error in pi is %19.15f (%f%%)\n", err, err * 100 / M_pi);
    }
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC; // end time of execution
    printf("Time elpased for openmp program with 2 thread is %f seconds\n", time_spent);

    return 0;
}