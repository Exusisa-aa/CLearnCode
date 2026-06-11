#include <stdio.h>

void exchange(void *x, void *y, int len);

int main()
{
  int a = 10;
  int b = 20;

  exchange(&a, &b, sizeof(int));

  printf("a = %d, b = %d\n", a, b);

  char c[6] = "abcde";
  char d[6] = "fghij";

  exchange(&c, &d, sizeof(char) * 5);
  printf("c = %s, d = %s\n", c, d);

  return 0;
}

void exchange(void *x, void *y, int len)
{
  char *xc = (char *)x;
  char *yc = (char *)y;
  char temp;

  for (int i = 0; i < len; i++)
  {
    temp = *xc;
    *xc = *yc;
    *yc = temp;

    xc++;
    yc++;
  }
}