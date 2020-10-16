#include <stdio.h>
#include <stdlib.h>
/* Define length of dot product vectors */
#define VECLEN 100000000
int main(int argc, char *argv[])
{
    int i, len = VECLEN;
    double *a, *b;
    double sum;
    printf("Starting omp_dotprod_serial\n"); /* Assign storage for dot product vectors */
    a = (double *)malloc(len * sizeof(double));
    b = (double *)malloc(len * sizeof(double)); /* Initialize dot product vectors */
    for (i = 0; i < len; i++)
    {
        a[i] = 10.0;
        b[i] = a[i];
    } /* Perform the dot product */
    sum = 0.0;
    for (i = 0; i < len; i++)
    {
        sum += (a[i] * b[i]);
    }
    printf("Done. Serial version: sum  =  %f \n", sum);
    free(a);
    free(b);
}