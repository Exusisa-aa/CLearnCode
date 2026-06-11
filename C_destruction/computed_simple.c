#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// 栈结构定义
typedef struct
{
  char data[MAX_SIZE];
  int top;
} CharStack;

typedef struct
{
  double data[MAX_SIZE];
  int top;
} DoubleStack;

// 初始化字符栈
void initCharStack(CharStack *stack)
{
  stack->top = -1;
}

// 初始化数字栈
void initDoubleStack(DoubleStack *stack)
{
  stack->top = -1;
}

// 字符栈是否为空
int isCharEmpty(CharStack *stack)
{
  return stack->top == -1;
}

// 数字栈是否为空
int isDoubleEmpty(DoubleStack *stack)
{
  return stack->top == -1;
}

// 字符栈入栈
void pushChar(CharStack *stack, char c)
{
  if (stack->top < MAX_SIZE - 1)
  {
    stack->data[++stack->top] = c;
  }
}

// 数字栈入栈
void pushDouble(DoubleStack *stack, double value)
{
  if (stack->top < MAX_SIZE - 1)
  {
    stack->data[++stack->top] = value;
  }
}

// 字符栈出栈
char popChar(CharStack *stack)
{
  if (!isCharEmpty(stack))
  {
    return stack->data[stack->top--];
  }
  return '\0';
}

// 数字栈出栈
double popDouble(DoubleStack *stack)
{
  if (!isDoubleEmpty(stack))
  {
    return stack->data[stack->top--];
  }
  return 0.0;
}

// 获取栈顶元素（字符）
char peekChar(CharStack *stack)
{
  if (!isCharEmpty(stack))
  {
    return stack->data[stack->top];
  }
  return '\0';
}

// 获取运算符优先级
int precedence(char op)
{
  switch (op)
  {
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 2;
  default:
    return 0;
  }
}

// 判断是否是运算符
int isOperator(char c)
{
  return (c == '+' || c == '-' || c == '*' || c == '/');
}

// 中缀表达式转后缀表达式
void infixToPostfix(char *infix, char *postfix)
{
  CharStack stack;
  initCharStack(&stack);

  int i, j = 0;
  for (i = 0; infix[i] != '\0'; i++)
  {
    // 如果是数字或小数点，则直接输出
    if (isdigit(infix[i]) || infix[i] == '.')
    {
      postfix[j++] = infix[i];
    }
    // 如果是左括号，入栈
    else if (infix[i] == '(')
    {
      pushChar(&stack, infix[i]);
    }
    // 如果是右括号，则将栈顶元素弹出直到遇到左括号
    else if (infix[i] == ')')
    {
      while (!isCharEmpty(&stack) && peekChar(&stack) != '(')
      {
        postfix[j++] = ' ';
        postfix[j++] = popChar(&stack);
      }
      if (!isCharEmpty(&stack) && peekChar(&stack) == '(')
      {
        popChar(&stack); // 弹出左括号
      }
    }
    // 如果是运算符
    else if (isOperator(infix[i]))
    {
      postfix[j++] = ' '; // 添加空格分隔数字
      while (!isCharEmpty(&stack) && precedence(peekChar(&stack)) >= precedence(infix[i]))
      {
        postfix[j++] = popChar(&stack);
        postfix[j++] = ' ';
      }
      pushChar(&stack, infix[i]);
    }
  }

  // 将栈中剩余的运算符全部弹出
  while (!isCharEmpty(&stack))
  {
    postfix[j++] = ' ';
    postfix[j++] = popChar(&stack);
  }

  postfix[j] = '\0';
}

// 计算后缀表达式
double evaluatePostfix(char *postfix)
{
  DoubleStack stack;
  initDoubleStack(&stack);

  int i;
  char numStr[MAX_SIZE];
  int numIndex = 0;

  for (i = 0; postfix[i] != '\0'; i++)
  {
    // 处理数字和小数点
    if (isdigit(postfix[i]) || postfix[i] == '.')
    {
      numStr[numIndex++] = postfix[i];
    }
    // 遇到空格，处理前面的数字
    else if (postfix[i] == ' ')
    {
      if (numIndex > 0)
      {
        numStr[numIndex] = '\0';
        pushDouble(&stack, atof(numStr));
        numIndex = 0;
      }
    }
    // 处理运算符
    else if (isOperator(postfix[i]))
    {
      // 确保栈中有足够的操作数
      if (stack.top >= 1)
      {
        double b = popDouble(&stack);
        double a = popDouble(&stack);
        double result;

        switch (postfix[i])
        {
        case '+':
          result = a + b;
          break;
        case '-':
          result = a - b;
          break;
        case '*':
          result = a * b;
          break;
        case '/':
          result = a / b;
          break;
        default:
          result = 0;
        }
        pushDouble(&stack, result);
      }
    }
  }

  // 最终栈中应该只剩一个元素，即结果
  if (!isDoubleEmpty(&stack))
  {
    return popDouble(&stack);
  }
  return 0;
}

int main()
{
  char infix[MAX_SIZE];
  char postfix[MAX_SIZE];

  printf("请输入一个简单的数学表达式（支持+、-、*、/、括号）：\n");
  fgets(infix, sizeof(infix), stdin);

  // 移除换行符
  if (infix[strlen(infix) - 1] == '\n')
  {
    infix[strlen(infix) - 1] = '\0';
  }

  // 转换为后缀表达式
  infixToPostfix(infix, postfix);
  printf("后缀表达式：%s\n", postfix);

  // 计算后缀表达式的结果
  double result = evaluatePostfix(postfix);
  printf("计算结果：%.2f\n", result);

  return 0;
}