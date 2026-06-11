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
  char x = stack->data[stack->top];
  stack->top--;
  return x;
}

int judgeArray(char *arr, int length)
{
  // 创建栈
  SqStack *stack;
  createStack(&stack);

  for (int i = 0; i < length; i++)
  {
    if (arr[i] == 'i')
    {
      push(stack, 1);
    }
    else if (arr[i] == 'o')
    {
      if (pop(stack) == -1)
      {
        free(stack);
        return 0;
      }
    }
  }

  free(stack);
  return 1;
}

int main()
{
  // 创建数组
  char rightArr[] = {'i', 'i', 'i', 'o', 'o', 'i', 'o', 'o'};
  char wrongArr[] = {'i', 'o', 'o', 'i', 'i', 'i', 'o', 'o'};

  if (judgeArray(rightArr, 8))
  {
    printf("数组是正确的！\n");
  }
  else
  {
    printf("数组是错误的！\n");
  }

  if (judgeArray(wrongArr, 8))
  {
    printf("数组是正确的！\n");
  }
  else
  {
    printf("数组是错误的！\n");
  }
}