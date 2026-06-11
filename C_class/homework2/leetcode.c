#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int val;
  struct node *next;
} node;

typedef struct
{
  int size;
  node *head;
} nodeList;

// 自己写了一遍写不出来，花了40分钟，条件太少了，还要时间复杂度为O(n),以下是问ai的结果
int isPalindrome(node *head)
{
  if (head == NULL || head->next == NULL)
  {
    return 1;
  }

  node *slow = head;
  node *fast = head;

  while (fast->next != NULL && fast->next->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
  }

  node *secondHalf = slow->next;
  node *prev = NULL;

  while (secondHalf != NULL)
  {
    node *next = secondHalf->next;
    secondHalf->next = prev;
    prev = secondHalf;
    secondHalf = next;
  }

  node *firstHalf = head;
  secondHalf = prev;

  int result = 1;
  while (prev != NULL)
  {
    if (firstHalf->val != prev->val)
    {
      result = 0;
      break;
    }
    firstHalf = firstHalf->next;
    prev = prev->next;
  }

  return result;
}