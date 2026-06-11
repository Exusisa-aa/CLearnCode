#include <stdio.h>
#include <string.h>

void findMax(char *str[], int len);
int main()
{
  char *str1 = "hellodwad";
  char *str2 = "worlddwadawdaw";
  char *str3 = "hello worldwadawd";
  char *str4 = "hello worldddwaadawdwad";
  char *str5 = "hello worldddawd";
  char *strs[] = {str1, str2, str3, str4, str5};
  findMax(strs, 5);
}

void findMax(char *str[], int len)
{
  // 用一个数组记录每个字符串的长度
  int tempNum = 0;
  int lens[len];
  for (int i = 0; i < len; i++)
  {
    for (int j = 0; j < (int)strlen(str[i]); j++)
    {
      tempNum++;
    }
    lens[i] = tempNum;
    tempNum = 0;
  }

  // 找到最大值
  int tempMax = lens[0];
  for (int i = 0; i < len; i++)
  {
    if (lens[i] > tempMax)
    {
      tempMax = lens[i];
    }
  }

  // 通过最大值找到最大字符串
  for (int i = 0; i < len; i++)
  {
    if ((int)strlen(str[i]) == tempMax)
    {
      printf("%s\n", str[i]);
    }
  }
}