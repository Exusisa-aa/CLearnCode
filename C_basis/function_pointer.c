#include <stdio.h>

void method1();
int method2(int num1, int num2);

int main()
{
  void (*p1)() = method1;
  int (*p2)(int, int) = method2;
  p1();
  printf("%d\n", p2(1, 2));
}

void method1()
{
  printf("method1\n");
}

int method2(int num1, int num2)
{
  printf("method2\n");
  return num1 + num2;
}