#include <stdio.h>

int main()
{
  int n;
  int arr[n][n];
  int sum;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      sum += arr[i][j];
    }
  }
  // 时间复杂度为O(n^2)

  int a, b, c;
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  int sortArr[] = {a, b, c};
  for (int i = 0; i < 3; i++)
  {
    for (int j = i + 1; j < 3; j++)
    {
      if (sortArr[i] > sortArr[j])
      {
        int temp = sortArr[i];
        sortArr[i] = sortArr[j];
        sortArr[j] = temp;
      }
    }
  }
  // 时间复杂度为O(1)

  int max, min;
  int arr0[n];
  for (int i = 0; i < n; i++)
  {
    if (arr0[i] > max)
    {
      max = arr0[i];
    }
    if (arr0[i] < min)
    {
      min = arr0[i];
    }
  }
  // 时间复杂度为O(n)
}