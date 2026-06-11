#include <stdio.h>

int main()
{
  union
  {
    int a[3];
    long k;
    char c[4];
  } r, *s = &r;

  s->a[0] = 0x39;
  s->a[1] = 0x38;
  printf("%x\n", s->c[0]);
}