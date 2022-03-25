/*
    优化 用现有的函数递归，不再新建函数
*/
#include <stdlib.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *sortedArrayToBST(int *nums, int numsSize)
{
    if (numsSize == 0)
    {
        return NULL;
    }
    int mid = (0 + numsSize - 1) / 2;
    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    //递归处理左子树
    root->left = sortedArrayToBST(nums, mid);
    root->right = sortedArrayToBST(nums + mid + 1, numsSize - mid - 1);
    return root;
}