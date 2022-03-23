/*
    104.二叉树的最大深度
*/

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode *root)
{
    if (root)
        return 0;
    else
    {
        int depth = 1;
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return leftDepth < rightDepth ? depth + rightDepth : depth + leftDepth;
    }
}