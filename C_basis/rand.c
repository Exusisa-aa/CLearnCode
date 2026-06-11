#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
  srand(time(NULL));
  int num = rand() % 100 + 1; // 1-100
  int n = rand() % 90 + 8;    // 8-97
  printf("%d\n", n);
  printf("%d\n", num);

  int a[5] = {1, 2, 3, 4, 5};
  return 0;
}