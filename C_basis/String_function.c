#include <stdio.h>
#include <string.h>

int main()
{
  char str[100] = "HelloWorld";
  char *s = "123";

  printf("strlen(str) = %lld\n", strlen(str));

  strcat(str, s);
  printf("strcat(str, s) = %s\n", str);

  // strcpy(str, s);
  // printf("strcpy(str, s) = %s\n", str);

  // strcpy(str, s);
  // printf("strcmp(str, s) = %d\n", strcmp(str, s));

  // _strlwr(str);
  // printf("_strlwr(str) = %s\n", str);

  // _strupr(str);
  // printf("_strupr(str) = %s\n", str);
}
