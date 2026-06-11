#include <stdio.h>

int main()
{
  int arr0[3][5] = {
      {11, 22, 33, 44, 55},
      {444, 555, 666, 777, 888},
      {7777, 8888, 9999, 1111, 2222}};

  int(*p)[5] = arr0;

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      printf("%d ", *(*p + j));
    }
    printf("\n");
    p++;
  }

  int arr1[] = {11, 22, 33, 44, 55};
  int arr2[] = {444, 555, 666, 777, 888};
  int arr3[] = {7777, 8888, 9999, 1111, 2222};
  int *arr[] = {arr1, arr2, arr3};

  int **p2 = arr;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      printf("%d ", *(*p2 + j));
    }
    printf("\n");
    p2++;
  }
}