#include <stdio.h>

int main()
{
  struct node
  {
    int n;
    struct node *next;
  } *p;
  struct node x[3] = {{2, x + 1}, {4, x + 2}, {6, NULL}};
  // x是数组的首地址
  p = x;
  printf("%d\n", (*p).n);
  printf("%d\n", p->n);
  printf("%d\n", (*((*p).next)).n);
  printf("%d\n", p->next->n);
}