#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_str1()
{
  char *p = "abcdef2";

  return p;
}

char *get_str2()
{
  char *q = "abcdef2";

  return q;
}

int main()
{
  char *p = NULL;
  char *q = NULL;

  p = get_str1();
  printf("p = %s p = %p\n", p, p);

  q = get_str2();
  printf("q = %s q = %p\n", q, q);

  printf("\n");
  return 0;
}
