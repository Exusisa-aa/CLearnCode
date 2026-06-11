#include <stdio.h>

void findMaxAndMin(int arr[], int len, int *max, int *min);
int main()
{

  int arr[] = {95, 64, 94, 12, 544, 89, 35, 2};
  int max = arr[0];
  int min = arr[0];
  int len = sizeof(arr) / sizeof(int);
  findMaxAndMin(arr, len, &max, &min);
  printf("max = %d, min = %d\n", max, min);
}

void findMaxAndMin(int arr[], int len, int *max, int *min)
{
  for (int i = 0; i < len; i++)
  {
    if (arr[i] > *max)
    {
      *max = arr[i];
    }

    if (arr[i] < *min)
    {
      *min = arr[i];
    }
  }
}