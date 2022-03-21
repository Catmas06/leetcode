/*
    19. 删除链表的倒数第 N 个结点
        给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
*/

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    struct ListNode *tail = head;
    struct ListNode *pointer = head;
    struct ListNode *pre = (struct ListNode *)malloc(sizeof(struct ListNode));
    //让pre与head都指向头结点
    pre->next = head;
    head = pre;
    //确定被删除对象与表尾的间距
    while (n)
    {
        tail = tail->next;
        n--;
    }
    // tail指向表尾，pointer指向被删除元素
    while (tail)
    {
        pre = pointer;
        pointer = pointer->next;
        tail = tail->next;
    }
    pre->next = pointer->next;
    free(pointer);
    return head->next;
}