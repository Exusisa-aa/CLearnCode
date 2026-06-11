#include <stdio.h>

int find(int arr[], int len, int num);
void bubbleSort(int arr[], int n);

int main()
{

  int arr[] = {85, 95, 21, 6, 48, 52, 49, 35, 74};
  int len = sizeof(arr) / sizeof(int);
  bubbleSort(arr, len);
  for (int i = 0; i < len; i++)
  {
    printf("%d ", arr[i]);
  }

  printf("\n");

  int index = find(arr, len, 96);
  printf("index:%d", index);
  return 0;
}

int find(int arr[], int len, int num)
{
  int max = len - 1;
  int min = 0;

  while (max >= min)
  {
    int mid = (max + min) / 2;
    if (num > arr[mid])
    {
      min = mid + 1;
    }
    else if (num < arr[mid])
    {
      max = mid - 1;
    }
    else
    {
      return mid;
    }
  }

  return -1;
}

void bubbleSort(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        // 交换元素
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}