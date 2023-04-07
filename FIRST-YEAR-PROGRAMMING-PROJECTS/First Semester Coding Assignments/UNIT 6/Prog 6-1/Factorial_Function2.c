#include <stdio.h>

int factorial(int n);

int main(void)
{
  // Call the function to find the factorial of the integers from 1 ... 30
  for (int i = 1; i <= 30; i++)
    printf("factorial(%d) = %d\n", i, factorial(i));
  
  return 0;
}

// Returns the factorial of n using recursion, see explanation below
int factorial(int n)
{
  if (n == 1) return 1;
  else return n * factorial(n-1);
}