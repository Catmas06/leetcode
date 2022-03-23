/*
    98. 验证二叉搜索树
    思想
        - 树根的取值范围是无限制的，并将孩子划分出两个区间[ ,n)、(n, ]
        - 第二层的两个节点l、r,又将孩子划分出四个区间 [ ,l),(l n),(n,r),(r, ]
        - 每向下一层，各个节点的取值范围都在缩小，且其取值受到多个父节点的叠加约束，而不受孩子节点的约束
    据此可设计相应递归算法
        - 每次通过参数传递区间
        - 判断本节点是否符合，再依据本节点的值更新约束条件，递归的处理左右孩子节点
*/
#include <stdbool.h>
#define MIN_VAL -2147483648
#define MAX_VAL 2147483647

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

//判断当前节点是否有效
bool isValidBSTNode(struct TreeNode *node, long min, long max)
{
    //递归出口，节点为空时默认符合
    if (!node)
        return true;
    //当节点值超出区间范围时
    if (node->val <= min && node->val >= max)
        return false;
    //递归判断左右孩子节点是否有效
    if (isValidBSTNode(node->left, min, node->val) && isValidBSTNode(node->right, node->val, max))
        return true;
    else
        return false;
}

bool isValidBST(struct TreeNode *root)
{
    //结点为空，默认符合
    if (!root && !root)
        return true;
    return isValidBSTNode(root, MIN_VAL, MAX_VAL);
}