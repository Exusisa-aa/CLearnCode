#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *reverseString(char *str);
int main()
{
  char *buf = "hello world";
  printf("%s\n", reverseString(buf));
  return 0;
}

char *reverseString(char *str)
{
  int n = strlen(str);
  char *temp = (char *)malloc((n + 1) * sizeof(char));
  for (int i = 0; i < n; i++)
  {
    temp[i] = str[n - i - 1];
  }
  temp[n] = '\0';
  return temp;
}