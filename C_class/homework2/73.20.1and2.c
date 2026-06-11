#include <stdio.h>
#include <stdlib.h>

// 节点结构
typedef struct node
{
  int data;
  struct node *next;
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

  if (list->size == 0)
  {
    list->head = newNode;
    list->tail = newNode;
  }
  else
  {
    list->tail->next = newNode;
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

  if (index - 1 < 0 || index - 1 > list->size)
  {
    printf("out of index\n");
    return;
  }

  if (index - 1 == 0) // 插头
  {
    newNode->next = list->head; // 将新节点指向头节点
    list->head = newNode;       // 将新节点设为头节点
  }
  else if (index - 1 == list->size) // 插尾
  {
    list->tail->next = newNode; // 将尾结点指向新节点
    list->tail = newNode;       // 将新节点设为尾节点
  }
  else
  {
    node *preNode = list->head;
    for (int i = 0; i < index - 2; i++)
    {
      preNode = preNode->next; // 找到插入位置的上一个节点（旧结点）
    }
    newNode->next = preNode->next; // 将新节点指向旧节点的下一个节点
    preNode->next = newNode;       // 将旧节点指向新节点
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
      for (int i = 0; i < index - 2; i++)
      {
        preNode = preNode->next; // 找到删除位置的上一个节点（旧结点）
      }
      node *delNode = preNode->next;       // 记住删除节点
      preNode->next = preNode->next->next; // 将旧节点指向旧节点的下下个节点
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
    else
    {
      curNode = curNode->next;
    }
  }
  return -1;
}

void printDifference(nodeList *list1, nodeList *list2)
{
  int i = 1;
  node *nodeInList1 = list1->head;

  while (nodeInList1 != NULL && i <= list1->size)
  {
    int flag = 1;
    node *nodeInList2 = list2->head;
    int j = 1;

    while (nodeInList2 != NULL && j <= list2->size)
    {
      if (nodeInList1->data == nodeInList2->data)
      {
        node *nextNode = nodeInList1->next;

        delete (list1, i); // 删除节点
        delete (list2, j); // 删除节点

        flag = 0; // 不打印
        i--;      // 删除节点后，索引减1

        nodeInList1 = nextNode;
        break;
      }
      nodeInList2 = nodeInList2->next;
      j++; // 索引加1
    }

    if (flag)
    {
      printf("%d ", nodeInList1->data);
      nodeInList1 = nodeInList1->next;
    }
    i++; // 索引加1
  }
  printf("\n");
}
int main()
{
  nodeList *list1;
  createList(&list1);
  push(list1, 1);
  push(list1, 2);
  push(list1, 3);
  push(list1, 4);
  push(list1, 5);

  nodeList *list2;
  createList(&list2);
  push(list2, 3);
  push(list2, 4);
  push(list2, 5);
  push(list2, 6);
  push(list2, 7);

  printDifference(list1, list2);

  free(list1);
  free(list2);

  return 0;
}
