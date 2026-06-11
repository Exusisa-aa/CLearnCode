#include <stdio.h>

int main()
{
  int a = 10;
  int *p = &a;

  printf("%d\n", *p);

  *p = 300;
  printf("%d\n", a);
  printf("%d\n", *p);

  return 0;
}