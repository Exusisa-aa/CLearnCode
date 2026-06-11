#include <stdio.h>
#include <time.h>

int main()
{
  long long t = time(NULL);
  printf("%lld\n", t);
  return 0;
}