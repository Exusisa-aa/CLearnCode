#include <stdio.h>

int main()
{
  int arr[] = {10, 20, 30, 40, 50};

  int *p = arr;
  int *pp = &arr[0];

  for (int i = 0; i < 5; i++)
  {
    printf("%d\n", *p++);
    printf("%d\n", *pp++);
  }

  printf("%lld\n", sizeof(arr));
}