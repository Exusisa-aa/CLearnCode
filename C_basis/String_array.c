#include <stdio.h>

int main()
{
  char arr1[5][100] = {"zhangsan", "lisi", "wangwu", "zhaoliu", "sunqiu"};
  char *arr2[5] = {"zhangsan", "lisi", "wangwu", "zhaoliu", "sunqiu"};

  for (int i = 0; i < 5; i++)
  {
    printf("%s\n", arr1[i]);
  }

  for (int i = 0; i < 5; i++)
  {
    printf("%s\n", arr2[i]);
  }
}