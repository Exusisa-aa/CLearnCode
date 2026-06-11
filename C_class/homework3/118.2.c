#include <stdio.h>
#include <stdlib.h>

// 节点结构
typedef struct node
{
  int data;
  struct node *next;
} node;

// 定义顺序栈结构体
typedef struct LinkStack
{
  node *top;
  int size;
} LinkStack;

void createStack(LinkStack **stack)
{
  *stack = (LinkStack *)malloc(sizeof(LinkStack));
  (*stack)->top = NULL;
  (*stack)->size = 0;
}

void push(LinkStack *stack, int x)
{
  node *newNode = (node *)malloc(sizeof(node));
  newNode->data = x;
  newNode->next = stack->top;
  stack->top = newNode;
  stack->size++;
}

int pop(LinkStack *stack)
{
  if (stack->top == NULL)
  {
    printf("栈已空，无法出栈！\n");
    return -1;
  }
  int x = stack->top->data;
  node *delNode = stack->top;
  stack->top = stack->top->next;
  free(delNode);
  stack->size--;
  return x;
}

int getTop(LinkStack *stack)
{
  if (stack->top == NULL)
  {
    printf("栈已空，无法获取栈顶元素！\n");
    return -1;
  }
  return stack->top->data;
}

int isEmpty(LinkStack *stack)
{
  if (stack->top == NULL)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int isFull(LinkStack *stack)
{
  if (stack->size == 100)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void freeStack(LinkStack **stack)
{
  node *curNode = (*stack)->top;
  while (curNode != NULL)
  {
    node *deleteNode = curNode;
    curNode = curNode->next;
    free(deleteNode);
  }
  free(*stack);
  *stack = NULL;
}

int main()
{
  // 创建栈
  LinkStack *stack;
  createStack(&stack);

  // 判断非空
  if (!isEmpty(stack))
  {
    printf("栈非空！\n");
  }
  else
  {
    printf("栈已空！\n");
  }

  // 进栈
  push(stack, 1);
  push(stack, 2);
  push(stack, 3);
  push(stack, 4);
  push(stack, 5);

  // 判断非空
  if (!isEmpty(stack))
  {
    printf("栈非空！\n");
  }
  else
  {
    printf("栈已空！\n");
  }

  // 输出出栈序列
  while (!isEmpty(stack))
  {
    printf("%d ", pop(stack));
  }
  printf("\n");

  // 判断非空
  if (!isEmpty(stack))
  {
    printf("栈非空！\n");
  }
  else
  {
    printf("栈已空！\n");
  }

  // 释放栈空间
  freeStack(&stack);

  return 0;
}
