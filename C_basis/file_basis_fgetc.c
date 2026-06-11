#include <stdio.h>

int main()
{
  char *path = "K:\\study\\C\\code\\C_basis\\txt\\test.txt";
  FILE *file = fopen(path, "r");
  char c;

  while ((c = fgetc(file)) != -1)
  {
    printf("%c", c);
  }

  fclose(file);

  return 0;
}