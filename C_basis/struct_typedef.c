#include <stdio.h>

typedef struct student
{
  char name[20];
  int age;
} s;

int main()
{
  s stu1 = {"张三", 18};
  s stu2 = {"李四", 19};
  s stu3 = {"王五", 20};

  s students[] = {stu1, stu2, stu3};

  for (int i = 0; i < 3; i++)
  {
    printf("姓名：%s, 年龄：%d\n", students[i].name, students[i].age);
  }
}
