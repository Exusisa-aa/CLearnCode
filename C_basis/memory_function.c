#include <stdio.h>
#include <stdlib.h>

int main()
{
  int size = 50;
  int *p = (int *)malloc(size * sizeof(int));
  int *p1 = (int *)calloc(5, sizeof(int));

  for (int i = 0; i < size; i++)
  {
    *(p + i) = i * 10;
    printf("%d\n", *(p + i));
  }

  for (int i = 0; i < 5; i++)
  {
    printf("%d\n", *(p1 + i));
  }

  int *p2 = (int *)realloc(p1, 10 * sizeof(int));

  for (int i = 0; i < 10; i++)
  {
    printf("%d\n", *(p2 + i));
  }

  free(p);
  free(p2);
}