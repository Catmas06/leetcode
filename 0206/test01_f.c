/*
    206. 反转链表
        给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
*/
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head)
{
    if (!head)
        return NULL;
    //初始化pre数组
    struct ListNode *pre = (struct ListNode *)malloc(sizeof(struct ListNode));
    pre->next = NULL;
    struct ListNode *h_next = (struct ListNode *)malloc(sizeof(struct ListNode));
    //头插法
    while (head)
    {
        h_next = head->next;
        head->next = pre->next;
        pre->next = head;
        head = h_next;
    }
    return pre->next;
}

int main()
{
    printf("--\n");
    return 0;
}