#include <stdio.h>
#include <stdlib.h>

#define MAX_VEX 6
typedef struct
{
  char vexs[MAX_VEX];
  int arc[MAX_VEX][MAX_VEX];
} MGraph;

void init(MGraph *G)
{
  for (int i = 0; i < MAX_VEX; i++)
  {
    for (int j = 0; j < MAX_VEX; j++)
    {
      G->arc[i][j] = 0;
    }
  }
}

void print(MGraph *G)
{
  for (int i = 0; i < MAX_VEX; i++)
  {
    for (int j = 0; j < MAX_VEX; j++)
    {
      printf("%d ", G->arc[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  MGraph G;
  init(&G);
  G.vexs[0] = '0';
  G.vexs[1] = '1';
  G.vexs[2] = '2';
  G.vexs[3] = '3';
  G.vexs[4] = '4';
  G.vexs[5] = '5';

  G.arc[0][1] = 5;
  G.arc[0][3] = 7;
  G.arc[1][2] = 4;
  G.arc[2][0] = 8;
  G.arc[2][5] = 9;
  G.arc[3][2] = 5;
  G.arc[3][5] = 6;
  G.arc[4][3] = 5;
  G.arc[5][4] = 1;
  G.arc[5][0] = 3;

  print(&G);
}
