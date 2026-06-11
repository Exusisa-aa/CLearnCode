#include <stdio.h>

int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int *p = &arr[0];
  int *q = &arr[5];
  printf("%d\n", *p);
  printf("%d\n", *(p + 1));
  printf("%d\n", *q - *p);
}