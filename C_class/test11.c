#include <stdio.h>

typedef struct
{
  char name[20];
  int age;
} student;

int main()
{
  student s1 = {"张三", 18};
  student s2 = {"李四", 19};
  s1.age = s2.age;
  printf("%s %d\n", s1.name, s1.age);
}