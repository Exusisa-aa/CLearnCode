#include <stdio.h>
#include <time.h>

typedef struct
{
  int year;
  int month;
  int day;
} data;
int main()
{
  time_t t = time(NULL);
  data dataNow = {gmtime(&t)->tm_year + 1900, gmtime(&t)->tm_mon + 1, gmtime(&t)->tm_mday};
  int days = gmtime(&t)->tm_yday;
  printf("今天的日期是%d-%d-%d,今年已经过去了%d天,今天是第%d天", dataNow.year, dataNow.month, dataNow.day, days, days + 1);
}