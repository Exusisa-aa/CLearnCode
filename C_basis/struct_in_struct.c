#include <stdio.h>

struct message
{
  char phone[12];
  char mail[100];
};

typedef struct student
{
  char name[20];
  int age;
  struct message contact;
} S;

int main()
{
  S stu = {"Tom", 18, {"12345678901", "tom@mail.com"}};
  printf("Name: %s\n", stu.name);
  printf("Age: %d\n", stu.age);
  printf("Phone: %s\n", stu.contact.phone);
  printf("Mail: %s\n", stu.contact.mail);
  return 0;
}
