#include <stdio.h>

typedef struct student
{
  char name[20];
  int age;
} S;

void change_student(S *stu);

int main()
{
  S stu1 = {"xxx", 0};
  void (*p)(S *) = change_student;
  p(&stu1);

  printf("name:%s, age:%d\n", stu1.name, stu1.age);
  return 0;
}

void change_student(S *stu)
{
  printf("name:");
  scanf("%s", (*stu).name);
  printf("age:");
  scanf("%d", &(*stu).age);
}