#include <stdio.h>
void pr(int a[])
{
  a[0] = 1;
}
int main()
{
  int a[] = {5};
  pr(a);
  printf("œ‘ æ£∫%d", a[0]);
};