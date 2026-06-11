#include <stdio.h>

int main()
{
  char a[9] = {'L', 'a', 'n', 'g', 'u', 'a', 'g', 'e'};
  char *p = a;
  printf("%s\n", p);
  printf("%s\n", p + 2);
  printf("%s\n", p + 4);
  printf("%s\n", p + 6);
}