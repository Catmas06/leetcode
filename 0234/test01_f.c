/*
    234. 回文链表
        给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。
*/
#include <stdbool.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

bool isPalindrome(struct ListNode *head)
{
    if (!head)
        return true;
    struct ListNode *pre = (struct ListNode *)malloc(sizeof(struct ListNode));
    pre->next = head;
    struct ListNode *mid = pre, *right = pre;
    //将left指向中间位置
    while (right->next)
    {
        right = right->next;
        mid = mid->next;
        if (right->next)
            right = right->next;
    }
    //头插法
    struct ListNode *middle = (struct ListNode *)malloc(sizeof(struct ListNode));
    middle->next = NULL;
    while (mid->next)
    {
        struct ListNode *temp = mid->next->next;
        mid->next->next = middle->next;
        middle->next = mid->next;
        mid->next = temp;
    }
    while (middle && middle->val == pre->val)
    {
        middle = middle->next;
        pre = pre->next;
    }
    if (middle)
        return false;
    else
        return true;
}