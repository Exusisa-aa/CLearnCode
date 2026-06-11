#include <stdio.h>

int main()
{
  int arr0[3][5] = {{1, 2, 3, 4, 5}, {4, 5, 6, 0, 5}, {7, 8, 9, 0, 0}};

  int arr1[] = {10, 11, 12};
  int arr2[] = {13, 14, 15, 0};
  int arr3[] = {16, 17, 18, 0, 0};
  int *arr[] = {arr1, arr2, arr3};
  int len[] = {3, 4, 5};

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      printf("%d ", arr0[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < len[i]; j++)
    {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }

  return 0;
}