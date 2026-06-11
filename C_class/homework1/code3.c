#include <stdio.h>
#include <time.h>

// 自己设计
int findNumber1(int oldArr[], int length, int newArr[])
{
  int index = 0;
  int flag;
  for (int i = 0; i < length; i++)
  {
    flag = 1;
    if (oldArr[i] == 0)
    {
      continue;
    }
    else if (oldArr[i] == 1)
    {
      continue;
    }
    else if (oldArr[i] == 2)
    {
      newArr[index] = 2;
      index++;
    }
    else if (oldArr[i] > 2)
    {
      for (int j = 2; j < oldArr[i]; j++)
      {
        if (oldArr[i] % j == 0)
        {
          flag = 0;
          break;
        }
      }
      if (flag)
      {
        newArr[index] = oldArr[i];
        index++;
      }
    }
  }
  return index;
}

// AI设计
int findNumber2(int oldArr[], int length, int newArr[])
{
  int count = 0;

  for (int i = 0; i < length; i++)
  {
    int num = oldArr[i];
    int isPrime = 1;

    if (num <= 1)
    {
      isPrime = 0;
    }
    else
    {
      for (int j = 2; j * j <= num; j++)
      {
        if (num % j == 0)
        {
          isPrime = 0;
          break;
        }
      }
    }

    if (isPrime)
    {
      newArr[count] = num;
      count++;
    }
  }

  return count;
}

int main()
{
  clock_t start1, end1, start2, end2;
  double time1, time2;

  int oldArr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  int newArr1[20];
  int length1;
  start1 = clock();
  for (int j = 0; j < 10000000; j++)
  {
    length1 = findNumber1(oldArr1, 20, newArr1);
  }

  end1 = clock();
  for (int i = 0; i < length1; i++)
  {
    printf("%d ", newArr1[i]);
  }
  time1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
  printf("\nTime1: %f seconds\n", time1);

  printf("\n");

  int oldArr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  int newArr2[20];
  int length2;
  start2 = clock();
  for (int j = 0; j < 10000000; j++)
  {
    length2 = findNumber2(oldArr2, 20, newArr2);
  }
  end2 = clock();
  for (int i = 0; i < length2; i++)
  {
    printf("%d ", newArr2[i]);
  }
  time2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
  printf("\nTime2: %f seconds\n", time2);
  return 0;
}