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

  queue->data[queue->rear] = x;
  queue->rear = (queue->rear + 1) % maxSize;
  queue->size++;
}

int delete(MyCircularQueue *queue)
{
  if (queue->rear == queue->front)
  {
    printf("队列已空，无法删除\n");
    return -1;
  }

  int x = queue->data[queue->front];
  queue->front = (queue->front + 1) % maxSize;
  queue->size--;
  return x;
}

void printQueue(MyCircularQueue *queue)
{
  for (int i = queue->front; i < queue->front + queue->size; i++)
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

int main()
{
  // 创建队列
  MyCircularQueue *queue;
  createQueue(&queue);

  // 判断队列是否为空
  if (isEmpty(queue))
  {
    printf("队列已空\n");
  }
  else
  {
    printf("队列未空\n");
  }

  // 添加元素
  add(queue, 1);
  add(queue, 2);
  add(queue, 3);

  // 出队输出一个元素
  printf("%d\n", delete (queue));

  // 添加元素
  add(queue, 4);
  add(queue, 5);
  add(queue, 6);

  // 输出出队序列
  while (!isEmpty(queue))
  {
    printf("%d ", delete (queue));
  }

  // 释放队列空间
  freeQueue(&queue);

  return 0;
}
