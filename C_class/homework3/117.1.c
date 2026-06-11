#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

// 定义顺序栈结构体
typedef struct SqStack
{
  int data[MAXSIZE]; // 存储数据的数组
  int top;           // 栈顶指针，指向栈顶元素的位置
} SqStack;

void createStack(SqStack **stack)
{
  *stack = (SqStack *)malloc(sizeof(SqStack));
  (*stack)->top = -1;
}

void push(SqStack *stack, int x)
{
  if (stack->top == MAXSIZE - 1)
  {
    printf("栈已满，无法入栈！\n");
    return;
  }
  stack->top++;
  stack->data[stack->top] = x;
}

int pop(SqStack *stack)
{
  if (stack->top == -1)
  {
    printf("栈已空，无法出栈！\n");
    return -1;
  }
  int x = stack->data[stack->top];
  stack->top--;
  return x;
}

int getTop(SqStack *stack)
{
  if (stack->top == -1)
  {
    printf("栈已空，无法获取栈顶元素！\n");
    return -1;
  }
  return stack->data[stack->top];
}

int isEmpty(SqStack *stack)
{
  if (stack->top == -1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int isFull(SqStack *stack)
{
  if (stack->top == MAXSIZE - 1)
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
  // 创建栈
  SqStack *stack;
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
  free(stack);

  return 0;
}