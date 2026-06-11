#include <stdio.h>

struct man
{
  char *name;
  int age;
  double height;
  char gender;
};

int main()
{
  struct man Mike = {"Mike", 20, 1.7, 'M'};

  printf("Name: %s\n", Mike.name);
  printf("Age: %d\n", Mike.age);
  printf("Height: %.2f\n", Mike.height);
  printf("Gender: %c\n", Mike.gender);

  return 0;
}
