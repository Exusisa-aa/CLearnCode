#include <stdio.h>

struct student
{
  char name[20];
  int age;
};

int main()
{
  struct student stu1 = {"张三", 18};
  struct student stu2 = {"李四", 19};
  struct student stu3 = {"王五", 20};
  struct student students[] = {stu1, stu2, stu3};

  for (int i = 0; i < 3; i++)
  {
    struct student student = students[i];
    printf("姓名：%s, 年龄：%d\n", student.name, student.age);
  }

  return 0;
}
