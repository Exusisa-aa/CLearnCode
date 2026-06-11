#include <stdio.h>
#include <string.h>

struct stu
{
  int a;
  char b[10];
  double c;
};
void fun(struct stu *p);
int main()
{
  struct stu a = {1, "WangBing", 70.5};
  fun(&a);
  printf("%d %s %.lf\n", a.a, a.b, a.c);

  return 0;
}
void fun(struct stu *p)
{
  strcpy(p->b, "LiLi");
}