#include <stdio.h>

long long add(int n)
{
  if (n <= 0)
  {
    return 0;
  }

  long long sum = 0;
  long long factorial = 1;

  for (int i = 1; i <= n; i++)
  {
    factorial *= i;
    sum += factorial;
  }

  return sum;
}

int main()
{
  long long number = add(5);
  printf("%lld\n", number);
  return 0;
}