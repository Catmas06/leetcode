/*
    101. 对称二叉树
*/
#include <stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isEqual(struct TreeNode *root1, struct TreeNode *root2)
{
    if (!root1 && !root2)
        return true;
    else if (!root1 || !root2)
        return false;
    else if (root1->val == root2->val)
    {
        return isEqual(root1->left, root2->right) && isEqual(root1->right, root2->left);
    }
    else
        return false;
}

bool isSymmetric(struct TreeNode *root)
{
    if (!root)
        return true;
    return isEqual(root->left, root->right);
}