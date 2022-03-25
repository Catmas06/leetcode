/*
    102. 二叉树的层序遍历
    思想
        - 将当前访问的节点入队尾
        - 每次将队头节点出队，访问，并将左右节点入队尾
        - 手写队列
*/
#include <stdbool.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

//声明联合体，队头节点用来保存长度，其他队列节点用来保存元素，即二叉树节点指针
union UN
{
    int length;
    struct TreeNode *node;
};
//创建队列节点结构体
struct queenNode
{
    union UN key;
    struct queenNode *next;
};
//创建队伍结构体，包含队头指针与队尾指针
struct Queen
{
    struct queenNode *head;
    struct queenNode *tail;
} Queen;
//入队函数
void insertQueen(struct TreeNode *root)
{
    if (!root)
        return;
    struct queenNode *tmp = malloc(sizeof(struct queenNode));
    tmp->key.node = root;
    tmp->next = NULL;
    Queen.tail->next = tmp;
    Queen.head->key.length++;
    Queen.tail = Queen.tail->next;
    return;
}
//创始化队伍函数
void initQueen()
{
    Queen.head = malloc(sizeof(struct queenNode));
    Queen.head->next = NULL;
    Queen.head->key.length = 0;
    Queen.tail = Queen.head;
}
//出队函数
int popQueen()
{
    // if (isNull)
    //     return;
    struct queenNode *tmp = Queen.head->next;
    int ret = tmp->key.node->val;
    Queen.head->next = tmp->next;
    Queen.head->key.length--;
    free(tmp);
    return ret;
}
//判断队列是否为空（未用到）
bool isNull()
{
    if (Queen.head->next == Queen.tail)
        return true;
    else
        return false;
}
//层序遍历函数
int **levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes)
{
    *returnSize = 0;
    if (!root)
        return NULL;
    int **ret = malloc(sizeof(int *) * 2000);
    *returnColumnSizes = (int *)malloc(sizeof(int) * 2000);
    initQueen();
    insertQueen(root);
    int retSize = 1;
    while (Queen.head->key.length)
    {
        int temp = 0;
        (*returnColumnSizes)[*returnSize] = retSize;
        ret[*returnSize] = malloc(sizeof(int) * retSize);
        for (int i = 0; i < retSize; i++)
        {
            if (Queen.head->next->key.node->left)
            {
                insertQueen(Queen.head->next->key.node->left);
                temp++;
            }
            if (Queen.head->next->key.node->right)
            {
                insertQueen(Queen.head->next->key.node->right);
                temp++;
            }
            ret[*returnSize][i] = popQueen();
        }
        retSize = temp;
        (*returnSize)++;
    }
    return ret;
}

//测试用主函数
int main()
{
    struct TreeNode *r1 = malloc(sizeof(struct TreeNode));
    struct TreeNode *r2 = malloc(sizeof(struct TreeNode));
    struct TreeNode *r3 = malloc(sizeof(struct TreeNode));
    struct TreeNode *r4 = malloc(sizeof(struct TreeNode));
    struct TreeNode *r5 = malloc(sizeof(struct TreeNode));
    r1->val = 3;
    r2->val = 9;
    r3->val = 20;
    r4->val = 15;
    r5->val = 7;
    r1->left = r2;
    r1->right = r3;
    r2->left = NULL;
    r2->right = NULL;
    r3->left = r4;
    r3->right = r5;
    r4->left = NULL;
    r4->right = NULL;
    r5->left = NULL;
    r5->right = NULL;
    int *returnSize = malloc(sizeof(int));
    int **returnColumnSizes = (int **)malloc(sizeof(int *));
    levelOrder(r1, returnSize, returnColumnSizes);
    return;
}