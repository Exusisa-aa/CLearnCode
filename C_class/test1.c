#include <stdio.h>

struct People
{
  char name[64];
  int age;
};

typedef struct People People_student;

int main()
{
  int a = 10;
  int b[10];

  printf("b:%p, b+1:%p,&b:%p,&b+1:%p\n", b, b + 1, &b, &b + 1);
  printf("sizeof(a):%zu \n", sizeof(a));
  printf("sizeof(int*):%zu \n", sizeof(int *));
  printf("sizeof(b):%zu \n", sizeof(b));
  printf("sizeof(b[0]):%zu \n", sizeof(b[0]));
  printf("sizeof(*b):%zu \n", sizeof(*b));

  int *c[10];
  int d = 30;
  c[0] = &d;
  printf("%d\n", *c[0]);

  int e = 50;
  int *f = &e;
  printf("%d\n", *f);

  People_student ming = {"Ming", 18};
  printf("name:%s, age:%d\n", ming.name, ming.age);

  return 0;
}
