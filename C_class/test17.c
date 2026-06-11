#include <stdio.h>

// 将大数组定义为全局变量，避免栈溢出
int a[60][250][1000];

void fun()
{
  int i, j, k;
  // 调整循环顺序以提高缓存命中率：按内存排列顺序访问元素
  for (i = 0; i < 60; i++)
  {
    for (j = 0; j < 250; j++)
    {
      for (k = 0; k < 1000; k++)
      {
        a[i][j][k] = 0;
      }
    }
  }
}

int main()
{
  fun();
  printf("%d\n", a[0][0][0]);
  return 0;
}