#include <stdio.h>

int main()
{

  int number = 5;
  int *str = &number;

  printf("%n\n", str);

  printf("short:%zu \n", sizeof(short));
  printf("int:%zu \n", sizeof(int));
  printf("long:%zu \n", sizeof(long));
  printf("long long:%zu \n", sizeof(long long));
  printf("char:%zu \n", sizeof(char));
  printf("float:%zu \n", sizeof(float));
  printf("double:%zu \n", sizeof(double));
  printf("long double:%zu \n", sizeof(long double));
  printf("void:%zu \n", sizeof(void));
  printf("*str:%zu \n", sizeof(*str));

  char *str2 = "hello world";
  printf("*str2:%zu \n", sizeof(*str2));
  printf("%s\n", str2);

  int arr[5] = {1, 2, 3, 4, 5};
  int *str3 = arr;
  printf("*str3:%n \n", str3);

  return 0;
}