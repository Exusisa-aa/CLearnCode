#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// char *get_str()
// {
//   static char str[] = "abcdedsgads";
//   printf("str = %s\n", str);

//   return str;
// }

char *get_str2()
{
  char *tmp = (char *)malloc(100); // 用于在堆开创一块内存，失败返回NULL，成功返回void*
  if (tmp == NULL)
  {
    return NULL;
  }

  strcpy(tmp, "adsagldsjglk");

  return tmp;
}

int main()
{
  // char buf[128] = {0};

  // strcpy(buf, get_str());
  // printf("buf = %s\n", buf);

  char *p = get_str2();
  if (p != NULL)
  {
    printf("p = %s\n", p);

    free(p); // 释放堆内存中的p 但是不会释放p的指针空间，此时p为空指针

    p = NULL;//释放空指针p
  }
  printf("\n");
  return 0;
}