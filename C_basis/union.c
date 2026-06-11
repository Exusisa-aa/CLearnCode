#include <stdio.h>
#include <string.h>

typedef union money
{
  int moneyi;
  double moneyd;
  char moneyc[100];
} M;

int main()
{
  M m;
  strcpy(m.moneyc, "1000Íò");
  printf("%s\n", m.moneyc);
  printf("%zu\n", sizeof(m));

  return 0;
}