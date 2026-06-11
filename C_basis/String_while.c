#include <stdio.h>
#include <string.h>

int main()
{
  char str[100] = "ÄãºÃHello World!";
  printf("%s\n", str);

  for (int i = 0; i < (int)strlen(str); i++)
  {
    char ch = str[i];
    printf("%c", ch);
  }
}
