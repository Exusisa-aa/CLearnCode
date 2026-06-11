#include <stdio.h>

void printWIW(char *a);
int main()
{
  char *a = "Turbo C";
  printf("%c\n", a[0]);
  printf("%s\n", a);

  char *p = &a[4];
  printf("%c\n", *p);

  return 0;
}
