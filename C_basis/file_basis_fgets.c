#include <stdio.h>

int main()
{
  char *path = "K:\\study\\C\\code\\C_basis\\txt\\test.txt";
  FILE *file = fopen(path, "r");
  char buf[1024];
  char *line;

  while ((line = fgets(buf, sizeof(buf), file)) != NULL)
  {
    printf("%s", line);
  }

  fclose(file);
  return 0;
}