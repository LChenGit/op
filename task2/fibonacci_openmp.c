#include <stdio.h>
#include <omp.h>
#include <time.h>


int fib(int n)
{
  int x, y, res;
  if (n < 2)
    return n;
  if (n < 20)
  {
    return (fib(n - 1) + fib(n - 2));
  }
  else
  {
    /* 
    Perform the code in an OpenMP parallel region for tasks
    */
#pragma omp task shared(x)
    x = fib(n - 1);
#pragma omp task shared(y)
    y = fib(n - 2);
#pragma omp taskwait
    res = x + y;
    return res;
  }
}

int main()
{
  omp_set_num_threads(16);
  int n, fibonacci;
  double starttime;
  printf("Please insert n, to calculate fib(n): \n");
  scanf("%d", &n);
  starttime = omp_get_wtime();

  fibonacci = fib(n);

  printf("fib(%d)=%d \n", n, fibonacci);
  printf("calculation took %lf sec\n", omp_get_wtime() - starttime);
  return 0;
}
