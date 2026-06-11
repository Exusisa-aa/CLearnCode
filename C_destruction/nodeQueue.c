#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *next;
} node;

typedef struct nodeQueue
{
  node *front;
  node *rear;
  int size;
} nodeQueue;

void createQueue(nodeQueue **queue)
{
  *queue = (nodeQueue *)malloc(sizeof(nodeQueue));
  (*queue)->front = NULL;
  (*queue)->rear = NULL;
  (*queue)->size = 0;
}

void push(nodeQueue *queue, int x)
{
  node *newNode = (node *)malloc(sizeof(node));
  newNode->data = x;
  newNode->next = NULL;

  if (queue->size == 0)
  {
    queue->front = newNode;
    queue->rear = newNode;
  }
  else
  {
    queue->rear->next = newNode;
    queue->rear = newNode;
  }
  queue->size++;
}

int pop(nodeQueue *queue)
{
  if (queue->size == 0)
  {
    printf("队列为空\n");
    return -1;
  }

  node *delNode = queue->front;
  int data = delNode->data;
  queue->front = delNode->next;
  free(delNode);
  queue->size--;
  if (queue->size == 0)
  {
    queue->rear = NULL;
    queue->front = NULL;
  }
  return data;
}

void freeQueue(nodeQueue **queue)
{
  node *cur = (*queue)->front;
  while (cur != NULL)
  {
    node *delNode = cur;
    cur = cur->next;
    free(delNode);
  }
  free(*queue);
  *queue = NULL;
}

int isEmpty(nodeQueue *queue)
{
  if (queue->size == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int main()
{
  // 创建队列
  nodeQueue *queue;
  createQueue(&queue);

  // 判断是否空
  if (queue->size == 0)
  {
    printf("队列已空\n");
  }
  else
  {
    printf("队列非空\n");
  }

  // 进队
  push(queue, 1);
  push(queue, 2);
  push(queue, 3);

  // 出队
  printf("%d\n", pop(queue));

  // 进队
  push(queue, 4);
  push(queue, 5);
  push(queue, 6);

  // 输出队列
  while (!isEmpty(queue))
  {
    printf("%d ", pop(queue));
  }

  // 释放队列空间
  freeQueue(&queue);

  return 0;
}
