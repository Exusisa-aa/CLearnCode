#include <stdio.h>

typedef struct
{
  int id;
  char name[100];
  double score;
} STUDENT;

int main()
{
  STUDENT students[10];
  for (int i = 1; i <= 10; i++)
  {
    printf("�������%dλѧ������Ϣ\n", i);
    printf("ѧ�ţ�");
    scanf("%d", &(students[i - 1].id));
    printf("������");
    scanf("%s", students[i - 1].name);
    printf("�ɼ���");
    scanf("%lf", &(students[i - 1].score));
  }

  for (int i = 0; i < 10; i++)
  {
    printf("��%dλѧ������Ϣ:ѧ��:%d,����:%s,�ɼ�:%.2lf\n", i + 1, students[i].id, students[i].name, students[i].score);
  }
}
