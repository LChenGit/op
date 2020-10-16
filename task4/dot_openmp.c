#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
/* Define length of dot product vectors */
#define VECLEN 100000000
#define NUMTHREADS 16

int main (int argc, char* argv[])
{
int i, tid, len=VECLEN, threads=NUMTHREADS;
double *a, *b;
double sum, psum;

printf("Starting omp_dotprod_openmp. Using %d threads\n",threads);

/* Assign storage for dot product vectors */
a = (double*) malloc (len*threads*sizeof(double));
b = (double*) malloc (len*threads*sizeof(double));
 
/* Initialize dot product vectors */
for (i=0; i<len*threads; i++) {
  a[i]=1.0;
  b[i]=a[i];
  }
/* Initialize global sum */
sum = 0.0;

/* 
   Perform the dot product in an OpenMP parallel region for loop with a sum reduction 
*/

#pragma omp parallel private(i,tid,psum) num_threads(threads) 
{
psum = 0.0;
tid = omp_get_thread_num();

#pragma omp for reduction(+:sum)
  for (i=0; i<len*threads; i++) 
    {
      sum += (a[i] * b[i]);
      psum = sum;
    }
printf("Thread %d partial sum = %f\n",tid, psum);
}

printf ("Done. OpenMP version: sum  =  %f \n", sum);

free (a);
free (b);
}  