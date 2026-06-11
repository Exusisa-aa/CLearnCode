#include <stdio.h>
#include <stdlib.h>

#define maxSize 10
// 环形队列结构体定义
typedef struct MyCircularQueue
{
  int data[maxSize]; // 存储数据的数组
  int front;         // 队首指针
  int rear;          // 队尾指针
  int size;          // 当前元素个数
} MyCircularQueue;

void createQueue(MyCircularQueue **queue)
{
  *queue = (MyCircularQueue *)malloc(sizeof(MyCircularQueue));
  (*queue)->front = 0;
  (*queue)->rear = 0;
  (*queue)->size = 0;
}

void add(MyCircularQueue *queue, int x)
{
  int index = queue->rear;
  if ((index + 1) % maxSize == queue->front)
  {
    printf("队列已满,无法插入\n");
    return;
  }

  queue->rear = (queue->rear + 1) % maxSize;
  queue->data[queue->rear] = x;
  queue->size++;
}

int delete(MyCircularQueue *queue)
{
  if (queue->rear == queue->front)
  {
    printf("队列已空，无法删除\n");
    return 0;
  }

  queue->front = (queue->front + 1) % maxSize;
  queue->size--;
  return queue->data[queue->front];
}

void printQueue(MyCircularQueue *queue)
{
  for (int i = queue->front + 1; i < queue->front + 1 + queue->size; i++)
  {
    printf("%d ", queue->data[i % maxSize]);
  }
  printf("\n");
}

void freeQueue(MyCircularQueue **queue)
{
  free(*queue);
  *queue = NULL;
}

int isEmpty(MyCircularQueue *queue)
{
  if (queue->rear == queue->front)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int isFull(MyCircularQueue *queue)
{
  int index = queue->rear;
  if ((index + 1) % maxSize == queue->front)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void outOfQueue(MyCircularQueue *queue)
{
  if (queue->size == 0)
  {
    printf("队列已空\n");
    return;
  }
  while (!isEmpty(queue))
  {
    int x = delete (queue);
    printf("%d ", x);
    if (isEmpty(queue))
    {
      return;
    }
    else
    {
      int y = delete (queue);
      add(queue, y);
    }
  }
}
int main()
{
  MyCircularQueue *queue;
  createQueue(&queue);

  add(queue, 1);
  add(queue, 2);
  add(queue, 3);
  add(queue, 4);
  add(queue, 5);
  add(queue, 6);
  add(queue, 7);
  add(queue, 8);

  outOfQueue(queue);

  return 0;
}
