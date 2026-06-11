#include <stdio.h>

// void exchange(int a, int b); 无法交换原因：该函数只交换了形参a和形参b的值，而不是交换a和b本身
void exchange(int *a, int *b);
int *silense();
void exchange1(int &a, int &b);
int main()
{
  int *c = silense();
  int a = 10;
  int b = 20;
  exchange(&a, &b);
  exchange1(a, b);

  printf("a = %d, b = %d\n", a, b);

  printf("c = %d\n", *c);

  return 0;
}

// void exchange(int a, int b)
// {
//   int temp;
//   temp = a;
//   a = b;
//   b = temp;
// }

void exchange(int *a, int *b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

void exchange1(int &a, int &b) // c++特供
{
  int temp;
  temp = a;
  a = b;
  b = temp;
}

int *silense()
{
  int a = 60;
  int *b = &a;
  return b;
}