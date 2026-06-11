#include <stdio.h>

int main()
{
  FILE *file1 = fopen("K:\\study\\C\\code\\C_basis\\∑Ω÷€.jpg", "rb");
  FILE *file2 = fopen("K:\\study\\C\\code\\C_basis\\copy\\∑Ω÷€.jpg", "wb");

  char buf[1024];
  int n;
  while ((n = fread(buf, 1, sizeof(buf), file1)) != 0)
  {
    fwrite(buf, 1, n, file2);
  }

  fclose(file2);
  fclose(file1);

  return 0;
}
