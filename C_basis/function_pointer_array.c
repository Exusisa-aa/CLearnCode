#include <stdio.h>
int plus(int a, int b);
int substrict(int a, int b);
int multipy(int a, int b);
int devide(int a, int b);
int main()
{
  int (*p[4])(int, int) = {plus, substrict, multipy, devide};
  int a, b;
  printf("input two number:");
  scanf("%d %d", &a, &b);
  int c;
  printf("input operation(1: plus, 2: substrict, 3: multipy, 4: devide):");
  scanf("%d", &c);
  int res = p[c - 1](a, b);
  printf("%d", res);
}

int plus(int a, int b)
{
  return a + b;
}
int substrict(int a, int b)
{
  return a - b;
}
int multipy(int a, int b)
{
  return a * b;
}
int devide(int a, int b)
{
  return a / b;
}
