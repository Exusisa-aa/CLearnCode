#include <stdio.h>
#include <stdlib.h>

// 节点结构
typedef struct node
{
  int data;
  struct node *next;
  struct node *pre;
} node;

// nodeList结构
typedef struct
{
  int size;
  node *head;
  node *tail;
} nodeList;

// 创建链表方法
void createList(nodeList **list)
{
  *list = (nodeList *)malloc(sizeof(nodeList));
  (*list)->size = 0;
  (*list)->head = NULL;
  (*list)->tail = NULL;
}

// 在尾部添加元素
void push(nodeList *list, int x)
{
  // 创建节点并赋值
  node *newNode = (node *)malloc(sizeof(node));
  newNode->data = x;
  newNode->next = NULL;
  newNode->pre = NULL;

  if (list->size == 0)
  {
    list->head = newNode;
    list->tail = newNode;
  }
  else
  {
    list->tail->next = newNode;
    newNode->pre = list->tail;
    list->tail = newNode;
  }

  list->size++;
}

// 在指定位置插入元素
void insert(nodeList *list, int x, int index) // 实际位置，非索引
{
  // 创建节点并赋值
  node *newNode = (node *)malloc(sizeof(node));
  newNode->data = x;
  newNode->next = NULL;
  newNode->pre = NULL;

  if (index - 1 < 0 || index - 1 > list->size)
  {
    printf("out of index\n");
    return;
  }

  if (index - 1 == 0) // 插头
  {
    newNode->next = list->head; // 将新节点指向头节点
    list->head->pre = newNode;  // 将新节点的pre指向头结点
    list->head = newNode;       // 将新节点设为头节点
  }
  else if (index - 1 == list->size) // 插尾
  {
    list->tail->next = newNode; // 将尾结点指向新节点
    newNode->pre = list->tail;  // 将新节点的pre指向尾结点
    list->tail = newNode;       // 将新节点设为尾节点
  }
  else
  {
    node *preNode = list->head;
    node *curNode = list->head;
    for (int i = 0; i < index - 2; i++)
    {
      preNode = preNode->next; // 找到插入位置的上一个节点（旧结点）
    }
    for (int i = 0; i < index - 1; i++)
    {
      curNode = curNode->next;
    }

    newNode->next = curNode;
    newNode->pre = preNode;
    preNode->next = newNode;
    curNode->pre = newNode;
  }
  list->size++;
}

// 打印链表
void printList(nodeList *list)
{
  node *curNode = list->head;
  while (curNode != NULL)
  {
    printf("%d ", curNode->data);
    curNode = curNode->next;
  }
  printf("\n");
}

// 删除节点
void delete(nodeList *list, int index)
{
  if (index - 1 < 0 || index - 1 >= list->size)
  {
    printf("out of index\n");
    return;
  }

  if (list->size == 1) // 如果只有一个节点
  {
    node *delNode = list->head;
    list->head = NULL;
    list->tail = NULL;
    list->size--;
    free(delNode);
  }
  else
  {
    if (index == 1) // 删除头结点
    {
      node *delNode = list->head;
      list->head = list->head->next;
      list->head->pre = NULL;
      free(delNode);
      list->size--;
    }
    else if (index == list->size)
    {
      node *preNode = list->head;
      for (int i = 0; i < index - 2; i++)
      {
        preNode = preNode->next;
      }
      free(preNode->next);
      preNode->next = NULL;
      list->tail = preNode;
    }
    else
    {
      node *preNode = list->head;
      node *nextNode = list->head;
      for (int i = 0; i < index - 2; i++)
      {
        preNode = preNode->next; // 找到删除位置的上一个节点（旧结点）
      }
      for (int i = 0; i < index; i++)
      {
        nextNode = nextNode->next;
      }
      node *delNode = preNode->next; // 记住删除节点
      preNode->next = nextNode;      // 将旧节点指向旧节点的下下个节点
      nextNode->pre = preNode;
      free(delNode);
      list->size--;
    }
  }
}

int findByValue(nodeList *list, int x)
{
  node *curNode = list->head;
  for (int i = 0; i < list->size; i++)
  {
    if (curNode->data == x)
    {
      return (i + 1);
    }
    curNode = curNode->next;
  }
  return -1;
}

int main()
{
  // 创建链表
  nodeList *list;
  createList(&list);

  // 添加
  push(list, 1);
  push(list, 2);
  push(list, 3);
  push(list, 4);
  push(list, 5);
  printList(list);

  // 插入
  insert(list, 7, 3);
  printList(list);

  // 删除
  delete (list, 5);
  printList(list);
  printf("%d\n", list->size);

  // 查找
  int num = findByValue(list, 7);
  if (num == -1)
  {
    printf("没有该元素\n");
  }
  else
  {
    printf("位于第%d位", num);
  }

  return 0;
}
