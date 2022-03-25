/*
    二叉树层序遍历
*/
#include <stdlib.h>
#define MAXSIZE 2000

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int **levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes)
{
    *returnSize = 0;
    if (root == NULL)
    {
        return NULL;
    }
    //给需要传回的变量malloc空间
    int **ret = malloc(sizeof(int *) * MAXSIZE);
    *returnColumnSizes = malloc(sizeof(int) * MAXSIZE);

    //创建并初始化辅助队列，将根节点入队
    struct TreeNode *Queen[MAXSIZE];
    Queen[0] = root;
    int head = 0, tail = 1;
    while (head < tail)
    {
        int tempSize = tail - head;
        ret[*returnSize] = malloc(sizeof(int) * tempSize);
        (*returnColumnSizes)[*returnSize] = tempSize;
        for (int count = 0; count < tempSize; count++)
        {
            ret[*returnSize][count] = Queen[head + count]->val;
        }
        (*returnSize)++;
        //将队中元素出队，并将新元素入队
        while (tempSize > 0)
        {
            if (Queen[head]->left != NULL)
            {
                Queen[tail++] = Queen[head]->left;
            }
            if (Queen[head]->right != NULL)
            {
                Queen[tail++] = Queen[head]->right;
            }
            head++;
            tempSize--;
        }
    }
    return ret;
}