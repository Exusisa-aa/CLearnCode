#include <stdio.h>

int main()
{
  FILE *file = fopen("K:\\study\\C\\code\\C_basis\\txt\\write.txt", "w");

  char ch = fputc('c', file);
  printf("ch = %c\n", ch);

  int n = fputs("hello world", file);
  printf("n = %d\n", n);

  char buf[12] = "哈哈哈哈";
  int n1 = fwrite(buf, 1, sizeof(buf), file);
  printf("n1 = %d\n", n1);

  fclose(file);
  return 0;
}