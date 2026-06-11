#include <stdio.h>

int main()
{
  int number = -10;
  printf("%d\n", (number = number > 0 ? number : -number * 10, number -= 10, number *= 10, number * 10)); // 9000);
  return 0;
}