/*
    237. 删除链表中的节点
        请编写一个函数，用于 删除单链表中某个特定节点 。在设计函数时需要注意，你无法访问链表的头节点 head ，只能直接访问 要被删除的节点 。
        题目数据保证需要删除的节点 不是末尾节点 。
*/

struct ListNode
{
    int val;
    struct ListNode *next;
};

void deleteNode(struct ListNode *node)
{
    //创建后继结点
    struct ListNode *nextNode = node->next;
    node->val = nextNode->val;
    node->next = nextNode->next;
    free(nextNode);
}