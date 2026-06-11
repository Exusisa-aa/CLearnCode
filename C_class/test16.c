#include <stdio.h>

struct month
{
  char name[10];
  int days;
} year[12] = {
    {"January", 31},
    {"February", 29},
    {"March", 31},
    {"April", 30},
    {"May", 31},
    {"June", 30},
    {"July", 31},
    {"August", 31},
    {"September", 30},
    {"October", 31},
    {"November", 30},
    {"December", 31}};

int main()
{
  for (int i = 0; i < 12; i++)
  {
    printf("%s %d\n", year[i].name, year[i].days);
  }
}
