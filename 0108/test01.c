/*
    108. 将有序数组转换为二叉搜索树
        给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。
        高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。
    思想
        - 从中间开始构造二叉树，每次都将中间的值作为根节点，将左区间和右区间的中点作为孩子结点
*/
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void insertTree(int *nums, int low, int mid, int high, struct TreeNode *root)
{
    int left = (low + mid) / 2;
    int right = (mid + high + 1) / 2;
    if (left != mid)
    {
        root->left = malloc(sizeof(struct TreeNode));
        root->left->val = nums[left];
        root->left->left = NULL;
        root->left->right = NULL;
        insertTree(nums, low, left, mid - 1, root->left);
    }
    if (right != mid)
    {
        root->right = malloc(sizeof(struct TreeNode));
        root->right->val = nums[right];
        root->right->left = NULL;
        root->right->right = NULL;
        insertTree(nums, mid + 1, right, high, root->right);
    }
    return;
}

struct TreeNode *sortedArrayToBST(int *nums, int numsSize)
{
    int low = 0, high = numsSize - 1, mid = (low + high) / 2;
    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    root->val = nums[mid];
    root->left = NULL;
    root->right = NULL;
    insertTree(nums, low, mid, high, root);
    return root;
}

// int main()
// {
//     int nums[2] = {1, 3};
//     struct TreeNode *root = sortedArrayToBST(nums, 2);
//     return 0;
// }