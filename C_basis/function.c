#include <stdio.h>

int sum(int x, int y);
int main()
{
  printf("%d", sum(1, 2));
}

int sum(int x, int y)
{
  int z = x + y;
  return z;
}
