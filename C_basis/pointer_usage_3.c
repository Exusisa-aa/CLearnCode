#include <stdio.h>

int toMod(int a, int b, int *c);

int main()
{
  int a = 10;
  int b = 3;
  int c = 0;
  if (toMod(a, b, &c) == 0)
  {
    printf("%d\n", c);
  }
  else
  {
    printf("Error\n");
  }

  return 0;
}

int toMod(int a, int b, int *c)
{
  if (b != 0)
  {
    *c = a % b;
    return 0;
  }
  return -1;
}