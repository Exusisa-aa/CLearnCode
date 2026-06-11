#include <stdio.h>

int main()
{
  char *path = "K:\\study\\C\\code\\C_basis\\txt\\test.txt";
  FILE *file = fopen(path, "r");
  char buf[1024];
  int n;
  while ((n = fread(buf, 1, sizeof(buf), file)) != 0)
  {
    for (int i = 0; i < n; i++)
    {
      printf("%c", buf[i]);
    }
  }

  fclose(file);

  return 0;
}