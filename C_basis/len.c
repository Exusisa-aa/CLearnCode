#include <stdio.h>

void print_array1(int arr[], int len);
void print_array2(char arr[], int len);

int main()
{
  int arr1[3] = {1, 2, 3};
  char arr2[3] = {'a', 'b', 'c'};
  int len1 = sizeof(arr1) / sizeof(int);
  int len2 = sizeof(arr2) / sizeof(char);

  print_array1(arr1, len1);
  print_array2(arr2, len2);
}

void print_array1(int arr[], int len)
{
  for (int i = 0; i < len; i++)
  {
    printf("%d\n", arr[i]);
  }
}

void print_array2(char arr[], int len)
{
  for (int i = 0; i < len; i++)
  {
    printf("%d\n", arr[i]);
  }
}