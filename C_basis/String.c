#include <stdio.h>

int main()
{
  char str[8] = "你1234";
  printf("%s\n", str);
  str[6] = '5';
  printf("%s\n", str);

  char *str0 = "例子0111";
  char *str1 = "例子0111";
  printf("%p\n", str0);
  printf("%p\n", str1);
  return 0;
}