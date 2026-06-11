#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 6

typedef struct Node
{
  int data;
  int weight;
  struct Node *next;
} Node;

// 添加队列结构用于BFS
typedef struct Queue
{
  int items[MAX_SIZE];
  int front;
  int rear;
} Queue;

void initQueue(Queue *queue)
{
  queue->front = 0;
  queue->rear = 0;
}

void enqueue(Queue *queue, int item)
{
  queue->items[queue->rear] = item;
  queue->rear++;
}

int dequeue(Queue *queue)
{
  int item = queue->items[queue->front];
  queue->front++;
  return item;
}

int isQueueEmpty(Queue *queue)
{
  return queue->front == queue->rear;
}

void init(Node *list[MAX_SIZE])
{
  for (int i = 0; i < MAX_SIZE; i++)
  {
    list[i] = NULL;
  }
}

void add(Node *list[MAX_SIZE], int src, int dext, int weight)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = dext;
  newNode->weight = weight;

  newNode->next = list[src];
  list[src] = newNode;
}

void print(Node *list[MAX_SIZE])
{
  for (int i = 0; i < MAX_SIZE; i++)
  {
    printf("节点%d: ", i);
    Node *p = list[i];
    while (p != NULL)
    {
      printf("(%d,%d) ", p->data, p->weight);
      p = p->next;
    }
    printf("\n");
  }
}

void destroy(Node *list[MAX_SIZE])
{
  for (int i = 0; i < MAX_SIZE; i++)
  {
    Node *p = list[i];
    while (p != NULL)
    {
      Node *q = p;
      p = p->next;
      free(q);
    }
  }
}

// 深度优先搜索 (DFS) - 递归实现
void DFSUtil(Node *list[MAX_SIZE], int vertex, int visited[])
{
  // 标记当前节点为已访问并打印
  visited[vertex] = 1;
  printf("%d ", vertex);

  // 递归访问所有未访问的邻接节点
  Node *adjacent = list[vertex];
  while (adjacent != NULL)
  {
    int adjVertex = adjacent->data;
    if (!visited[adjVertex])
    {
      DFSUtil(list, adjVertex, visited);
    }
    adjacent = adjacent->next;
  }
}

// 深度优先搜索 (DFS)
void DFS(Node *list[MAX_SIZE], int startVertex)
{
  int visited[MAX_SIZE] = {0};
  printf("深度优先搜索结果 (从节点%d开始): ", startVertex);
  DFSUtil(list, startVertex, visited);
  printf("\n");
}

// 广度优先搜索 (BFS)
void BFS(Node *list[MAX_SIZE], int startVertex)
{
  int visited[MAX_SIZE] = {0};
  Queue queue;
  initQueue(&queue);

  // 标记起始节点为已访问并加入队列
  visited[startVertex] = 1;
  enqueue(&queue, startVertex);

  printf("广度优先搜索结果 (从节点%d开始): ", startVertex);

  // 当队列不为空时继续处理
  while (!isQueueEmpty(&queue))
  {
    // 出队并打印节点
    int currentVertex = dequeue(&queue);
    printf("%d ", currentVertex);

    // 将所有未访问的邻接节点加入队列
    Node *adjacent = list[currentVertex];
    while (adjacent != NULL)
    {
      int adjVertex = adjacent->data;
      if (!visited[adjVertex])
      {
        visited[adjVertex] = 1;
        enqueue(&queue, adjVertex);
      }
      adjacent = adjacent->next;
    }
  }
  printf("\n");
}

int main()
{
  Node *list[MAX_SIZE];
  init(list);

  add(list, 0, 1, 5);
  add(list, 0, 3, 7);
  add(list, 1, 2, 4);
  add(list, 2, 0, 8);
  add(list, 2, 5, 9);
  add(list, 3, 2, 5);
  add(list, 3, 5, 6);
  add(list, 4, 3, 5);
  add(list, 5, 4, 1);
  add(list, 5, 0, 3);

  print(list);

  DFS(list, 0);
  BFS(list, 0);

  return 0;
}