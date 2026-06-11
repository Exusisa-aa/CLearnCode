#include <stdio.h>
#include <stdlib.h>

#define max 100
typedef struct
{
  int data[max];
  int size;
} Aset;

// 创建
Aset createAset()
{
  Aset tempAset;
  tempAset.size = 0;
  return tempAset;
}
void createAsetAsPointer(Aset **aset) // 指向一个指针的地址
{
  *aset = (Aset *)malloc(sizeof(Aset)); // 解引用后就是该指针的原地址
  (*aset)->size = 0;
}

// 添加元素
void insert(Aset *aset, int x)
{
  if (x <= 0)
  {
    return;
  }

  if ((*aset).size != 0)
  {
    for (int i = 0; i < (*aset).size; i++)
    {
      if ((*aset).data[i] == x)
      {
        return;
      }
    }
    (*aset).data[(*aset).size] = x;
    (*aset).size++;
    return;
  }
  else
  {
    (*aset).data[(*aset).size] = x;
    (*aset).size++;
    return;
  }
}

// 添加数组元素
void insertAsArray(Aset *aset, int arr[], int length)
{
  for (int i = 0; i < length; i++)
  {
    insert(aset, arr[i]);
  }
}

// 打印
void printAset(Aset *aset)
{
  for (int i = 0; i < (*aset).size; i++)
  {
    printf("%d ", (*aset).data[i]);
  }
  printf("\n");
}

// 查找
void isExist(Aset *aset, int x)
{
  for (int i = 0; i < (*aset).size; i++)
  {
    if ((*aset).data[i] == x)
    {
      printf("Element exists on NO.%d\n", i + 1);
      return;
    }
  }
  printf("Element does not exist\n");
}

// 并集
Aset unionAset(Aset *aset1, Aset *aset2)
{
  Aset tempAset = createAset();
  for (int i = 0; i < (*aset1).size; i++)
  {
    insert(&tempAset, (*aset1).data[i]);
  }
  for (int i = 0; i < (*aset2).size; i++)
  {
    insert(&tempAset, (*aset2).data[i]);
  }

  return tempAset;
}

// 交集
Aset intersectionAset(Aset *aset1, Aset *aset2)
{
  Aset tempAset = createAset();
  for (int i = 0; i < (*aset1).size; i++)
  {
    for (int j = 0; j < (*aset2).size; j++)
    {
      if ((*aset1).data[i] == (*aset2).data[j])
      {
        insert(&tempAset, (*aset1).data[i]);
      }
    }
  }

  return tempAset;
}

// 差集
Aset differenceAset(Aset *aset1, Aset *aset2)
{
  Aset isnAset = createAset();
  Aset tempAset = createAset();
  int flag;
  isnAset = intersectionAset(aset1, aset2);
  for (int i = 0; i < (*aset1).size; i++)
  {
    for (int j = 0; j < isnAset.size; j++)
    {
      flag = 1;
      if (isnAset.data[j] == (*aset1).data[i])
      {
        flag = 0;
        break;
      }
    }
    if (flag)
    {
      insert(&tempAset, (*aset1).data[i]);
    }
  }

  return tempAset;
}

// free
void freeAset(Aset **aset) // 传入一级指针的地址，也就是二级指针
{
  free(*aset); // 解引用后就是该指针的原地址
  *aset = NULL;
}

int main()
{
  // 1. 在集合基础上创建Aset
  int arr1[] = {-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int arr2[] = {5, 5, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  Aset aset1 = createAset();
  Aset *aset2;
  createAsetAsPointer(&aset2); // 指针的地址是一个二级指针，故该函数参数为Aset **
  insertAsArray(&aset1, arr1, 12);
  insertAsArray(aset2, arr2, 13);
  // 2.输出打印
  printAset(&aset1); // 1 2 3 4 5 6 7 8 9 10
  printAset(aset2);  // 5 6 7 8 9 10 11 12 13 14 15
  // 3.判断是否存在某个元素
  isExist(&aset1, 5); // 存在
  isExist(aset2, 20); // 不存在
  // 4.并集
  Aset aset3 = unionAset(&aset1, aset2);
  printAset(&aset3); // 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
  // 5.交集
  Aset aset4 = intersectionAset(&aset1, aset2);
  printAset(&aset4); // 5 6 7 8 9 10
  // 6.差集
  Aset aset5 = differenceAset(&aset1, aset2);
  printAset(&aset5); // 1 2 3 4

  // free
  freeAset(&aset2);

  return 0;
}
