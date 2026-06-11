#include <stdio.h>

struct s1
{
  double a;
  char b;
  int c;
  char d;
};

struct s2
{
  double a;
  char b;
  char c;
  int d;
};

int main()
{
  struct s1 s1;
  struct s2 s2;

  printf("%zu\n", sizeof(s1));
  printf("%zu\n", sizeof(s2));

  return 0;
}
