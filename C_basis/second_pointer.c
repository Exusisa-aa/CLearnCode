#include <stdio.h>

int main()
{
  int a = 10;
  int b = 20;
  int *p = &a;
  int **pp = &p;
  *pp = &b;

  printf("a = %p\n", &a);
  printf("b = %p\n", &b);
  printf("p = %p\n", p);
  printf("pp = %p\n", pp);

  if (*pp == p)
  {
    printf("*pp == p");
  }
  if (pp == &p)
  {
    printf("pp == &p");
  }
}
