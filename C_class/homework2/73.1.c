#include <stdio.h>
#include <stdlib.h>

#define max 100
typedef struct
{
  int data[max];
  int size;
} sqlist;

void createSqlist(sqlist **list)
{
  *list = (sqlist *)malloc(sizeof(sqlist));
  (*list)->size = 0;
}

// 添加元素
void add(sqlist *list, int x)
{
  (*list).data[(*list).size] = x;
  (*list).size++;
  return;
}

// 插入元素
void insert(sqlist *list, int x, int index)
{
  if (index - 1 < 0 || index - 1 > (*list).size)
  {
    printf("out of index\n");
    return;
  }

  for (int i = (*list).size; i > index - 1; i--)
  {
    list->data[i] = list->data[i - 1]; // 最多插在末尾
  }

  (*list).data[index - 1] = x;
  (*list).size++;
}

// 打印元素
void printSqlist(sqlist *list)
{
  for (int i = 0; i < (*list).size; i++)
  {
    printf("%d ", (*list).data[i]);
  }
  printf("\n");
}

// 打印长度
void printLength(sqlist *list)
{
  printf("%d\n", (*list).size);
}

// 判断是否为空
void isEmpty(sqlist *list)
{
  if ((*list).size == 0)
  {
    printf("empty\n");
  }
  else
  {
    printf("not empty\n");
  }
}

// 打印特定元素
void printByIndex(sqlist *list, int index)
{
  if (index - 1 < 0 || index - 1 >= (*list).size)
  {
    printf("out of index\n");
    return;
  }
  printf("%d\n", (*list).data[index - 1]);
}

// 查找
void isExist(sqlist *list, int x)
{
  for (int i = 0; i < (*list).size; i++)
  {
    if ((*list).data[i] == x)
    {
      printf("Element exists on NO.%d\n", i + 1);
      return;
    }
  }
  printf("Element does not exist\n");
}

// 删除元素
void delete(sqlist *list, int index)
{
  if (index - 1 < 0 || index - 1 >= (*list).size)
  {
    printf("out of index\n");
    return;
  }

  for (int i = index - 1; i < (*list).size; i++)
  {
    (*list).data[i] = (*list).data[i + 1];
  }
  (*list).size--;
}

// free
void freeSqlist(sqlist **list)
{
  free(*list);
  *list = NULL;
}

int main()
{
  // 1.初始化顺序表
  sqlist *list;
  createSqlist(&list);

  // 2.依次插入1,2,3,4,5
  add(list, 1);
  add(list, 2);
  add(list, 3);
  add(list, 4);
  add(list, 5);

  // 3.打印顺序表
  printSqlist(list);

  // 4.打印长度
  printLength(list);

  // 5.判断是否为空
  isEmpty(list);

  // 6.打印第三个元素
  printByIndex(list, 3);

  // 7.查找元素5
  isExist(list, 5);

  // 8.在第四个元素位置插上6
  insert(list, 6, 4);

  // 9.打印顺序表
  printSqlist(list);

  // 10.删除第三个元素
  delete (list, 3);

  // 11.打印顺序表
  printSqlist(list);

  // 12.free
  freeSqlist(&list);

  return 0;
}
