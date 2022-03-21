/*
    21. 合并两个有序链表
*/
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

void insert(struct ListNode *dest, struct ListNode *src)
{
    assert(dest);
    assert(src);
    struct ListNode *tmp = src->next;
    src->next = tmp->next;
    tmp->next = dest->next;
    dest->next = tmp;
}

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode *pre_head1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *pre_head2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    pre_head1->next = list1;
    pre_head2->next = list2;
    struct ListNode *tmp1 = pre_head1;
    while (pre_head2->next)
    {
        // list1结束遍历，list2所有元素插入list1
        if (tmp1->next == NULL)
        {
            tmp1->next = pre_head2->next;
            break;
        }
        if (tmp1->next->val > pre_head2->next->val)
        {
            insert(tmp1, pre_head2);
        }
        tmp1 = tmp1->next;
    }
    return pre_head1->next;
}