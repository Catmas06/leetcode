/*
    141. 环形链表
        给你一个链表的头节点 head ，判断链表中是否有环。
        如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数pos来表示链表尾连接到链表中的位置（索引从 0 开始）。注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。
        如果链表中存在环 ，则返回 true 。 否则，返回 false 。

    思想：
        设置快慢两个指针，快走两步，慢走一步
        若存在环，则快慢指针一定会相遇
*/
#include <stdbool.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head)
{
    if (!head)
        return false;
    struct ListNode *fast = head, *slow = head;
    while (fast->next)
    {
        fast = fast->next;
        slow = slow->next;
        if (fast->next)
            fast = fast->next;
        //一旦fast->next为空，即表示无环
        else
            return false;
        if (fast == slow)
            return true;
    }
    return false;
}