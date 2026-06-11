#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
  int data;
  struct TreeNode *left;
  struct TreeNode *right;
} TreeNode;

typedef struct secondTree
{
  TreeNode *root;
} secondTree;

TreeNode *createNode(int data)
{
  TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void createSecondTree(secondTree **tree)
{
  *tree = (secondTree *)malloc(sizeof(secondTree));
  (*tree)->root = NULL;
}

void insert(secondTree *tree, int data)
{
  TreeNode *node = createNode(data);

  if (tree->root == NULL)
  {
    tree->root = node;
  }
  else
  {
    TreeNode *current = tree->root;
    while (current != NULL)
    {
      if (data < current->data)
      {
        if (current->left == NULL)
        {
          current->left = node;
          break;
        }
        else
        {
          current = current->left;
        }
      }
      else
      {
        if (current->right == NULL)
        {
          current->right = node;
          break;
        }
        else
        {
          current = current->right;
        }
      }
    }
  }
}

// 前序遍历 (根->左->右)
void preorderTraversal(TreeNode *root)
{
  if (root != NULL)
  {
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
  }
}

// 中序遍历 (左->根->右)
void inorderTraversal(TreeNode *root)
{
  if (root != NULL)
  {
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
  }
}

// 后序遍历 (左->右->根)
void postorderTraversal(TreeNode *root)
{
  if (root != NULL)
  {
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
  }
}

// Morris前序遍历
void morrisPreorderTraversal(TreeNode *root)
{
  TreeNode *current = root;

  while (current != NULL)
  {
    if (current->left == NULL)
    {
      // 没有左子树，访问当前节点，然后移动到右子树
      printf("%d ", current->data);
      current = current->right;
    }
    else
    {
      // 找到左子树中的最右节点（前驱节点）
      TreeNode *predecessor = current->left;
      while (predecessor->right != NULL && predecessor->right != current)
      {
        predecessor = predecessor->right;
      }

      if (predecessor->right == NULL)
      {
        // 建立线索连接
        printf("%d ", current->data); // 访问当前节点
        predecessor->right = current;
        current = current->left;
      }
      else
      {
        // 恢复树结构，断开线索连接
        predecessor->right = NULL;
        current = current->right;
      }
    }
  }
}

// Morris中序遍历
void morrisInorderTraversal(TreeNode *root)
{
  TreeNode *current = root;

  while (current != NULL)
  {
    if (current->left == NULL)
    {
      // 没有左子树，访问当前节点，然后移动到右子树
      printf("%d ", current->data);
      current = current->right;
    }
    else
    {
      // 找到左子树中的最右节点（前驱节点）
      TreeNode *predecessor = current->left;
      while (predecessor->right != NULL && predecessor->right != current)
      {
        predecessor = predecessor->right;
      }

      if (predecessor->right == NULL)
      {
        // 建立线索连接
        predecessor->right = current;
        current = current->left;
      }
      else
      {
        // 恢复树结构，断开线索连接
        printf("%d ", current->data); // 访问当前节点
        predecessor->right = NULL;
        current = current->right;
      }
    }
  }
}

// 翻转链表
TreeNode *reverseList(TreeNode *head)
{
  TreeNode *prev = NULL;
  TreeNode *current = head;

  while (current != NULL)
  {
    TreeNode *next = current->right;
    current->right = prev;
    prev = current;
    current = next;
  }

  return prev;
}

// 打印并恢复链表
void printAndRestore(TreeNode *head)
{
  // 先翻转链表
  TreeNode *reversed = reverseList(head);

  // 打印
  TreeNode *current = reversed;
  while (current != NULL)
  {
    printf("%d ", current->data);
    current = current->right;
  }

  // 再次翻转以恢复原状
  reverseList(reversed);
}

// 修复后的Morris后序遍历
void morrisPostorderTraversal(TreeNode *root)
{
  if (root == NULL)
    return;

  // 创建伪根节点
  TreeNode dummy = {0, root, NULL};
  TreeNode *current = &dummy;

  while (current != NULL)
  {
    if (current->left == NULL)
    {
      current = current->right;
    }
    else
    {
      // 找到中序前驱
      TreeNode *predecessor = current->left;
      while (predecessor->right != NULL && predecessor->right != current)
      {
        predecessor = predecessor->right;
      }

      if (predecessor->right == NULL)
      {
        // 建立线索
        predecessor->right = current;
        current = current->left;
      }
      else
      {
        // 移除线索并打印
        predecessor->right = NULL;
        printAndRestore(current->left);
        current = current->right;
      }
    }
  }
}
void printLeftAndRight(secondTree *tree, int data)
{
  if (tree->root == NULL)
  {
    return;
  }
  else
  {
    if (tree->root->data == data)
    {
      if (tree->root->left == NULL && tree->root->right == NULL)
      {
        printf("左节点:NULL,右节点:NULL");
      }
      else if (tree->root->left == NULL)
      {
        printf("左节点:NULL,右节点:%d", tree->root->right->data);
      }
      else if (tree->root->right == NULL)
      {
        printf("左节点:%d,右节点:NULL", tree->root->left->data);
      }
      else
      {
        printf("左节点:%d,右节点:%d", tree->root->left->data, tree->root->right->data);
      }

      return;
    }
    TreeNode *current = tree->root;
    while (current != NULL)
    {
      if (data < current->data)
      {
        if (current->left == NULL)
        {
          printf("未找到该节点");
          break;
        }
        else
        {
          if (current->left->data == data)
          {
            if (current->left->left == NULL && current->left->right == NULL)
            {
              printf("左节点:NULL,右节点:NULL");
            }
            else if (current->left->left == NULL)
            {
              printf("左节点:NULL,右节点:%d", current->left->right->data);
            }
            else if (current->left->right == NULL)
            {
              printf("左节点:%d,右节点:NULL", current->left->left->data);
            }
            else if (current->left->left != NULL && current->left->right != NULL)
            {
              printf("左节点:%d,右节点:%d", current->left->left->data, current->left->right->data);
            }
            return;
          }
          current = current->left;
        }
      }
      else
      {
        if (current->right == NULL)
        {
          printf("未找到该节点");
          break;
        }
        else
        {
          if (current->right->data == data)
          {
            if (current->right->left == NULL && current->right->right == NULL)
            {
              printf("左节点:NULL,右节点:NULL");
            }
            else if (current->right->left == NULL)
            {
              printf("左节点:NULL,右节点:%d", current->right->right->data);
            }
            else if (current->right->right == NULL)
            {
              printf("左节点:%d,右节点:NULL", current->right->left->data);
            }
            else if (current->right->left != NULL && current->right->right != NULL)
            {
              printf("左节点:%d,右节点:%d", current->right->left->data, current->right->right->data);
            }
            return;
          }
          current = current->right;
        }
      }
    }
  }
}

int getHeight(TreeNode *node)
{
  if (node == NULL)
  {
    return 0;
  }

  int leftHeight = getHeight(node->left);
  int rightHeight = getHeight(node->right);

  return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
}

void freeTreeNode(TreeNode *node)
{
  if (node != NULL)
  {
    freeTreeNode(node->left);
    freeTreeNode(node->right);
    free(node);
  }
}

void freeTree(secondTree **tree)
{
  if (*tree != NULL)
  {
    freeTreeNode((*tree)->root);
    free(*tree);
    *tree = NULL;
  }
}

int main()
{
  // 构建题中的二叉树结构
  secondTree *tree;
  createSecondTree(&tree);
  insert(tree, 10);
  insert(tree, 2);
  insert(tree, 12);
  insert(tree, 1);
  insert(tree, 9);
  insert(tree, 11);
  insert(tree, 13);
  insert(tree, 4);
  insert(tree, 14);
  insert(tree, 3);
  insert(tree, 6);
  insert(tree, 5);
  insert(tree, 7);
  insert(tree, 8);

  // 遍历二叉树（递归）
  printf("前序遍历:");
  preorderTraversal(tree->root);
  printf("\n");

  printf("中序遍历:");
  inorderTraversal(tree->root);
  printf("\n");

  printf("后序遍历:");
  postorderTraversal(tree->root);
  printf("\n");

  // 遍历二叉树（非递归）
  printf("前序遍历:");
  morrisPreorderTraversal(tree->root);
  printf("\n");

  printf("中序遍历:");
  morrisInorderTraversal(tree->root);
  printf("\n");

  printf("后序遍历:");
  morrisPostorderTraversal(tree->root);
  printf("\n");

  // 获取节点4的左右节点
  printLeftAndRight(tree, 4);

  // 获取二叉树的高度
  printf("\n高度:%d", getHeight(tree->root));

  // 释放二叉树
  freeTree(&tree);
}
