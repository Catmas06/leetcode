/*
82. 删除排序链表中的重复元素 II
	给定一个已排序的链表的头 head，删除原始链表中所有重复数字的节点，只留下不同的数字。返回已排序的链表。
*/
#include<malloc.h>
#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
 };

//传入要删除的前一个结点
//循环删除
void delete_c(struct ListNode* head) {
    struct ListNode* p = head->next;
    while (p->next && p->val == p->next->val) {
        p = p->next;
    }
    head->next = p->next;
}

struct ListNode* deleteDuplicates(struct ListNode* head) {
    //无需判断，值唯一
    if (!head || !(head->next)) return head;

    //创建哑结点
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->next = head;

    struct ListNode* p = dummy, * q,* r;
    while (p->next && p->next->next) {
        q = p->next;
        r = q->next;
        if (q->val == r->val) {
            //p为前置结点，删除p后相同元素
            delete_c(p);
        }
        else p = q;
    }
    return dummy->next;
}

//打印链表
void print_s(struct ListNode* head) {
    while (head->next != NULL) {
        printf("%d ->", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

//测试程序
int main() {
    int n = 3;
    struct ListNode* List1 = (struct ListNode*)malloc(sizeof(struct ListNode*));
    List1->next = (struct ListNode*)malloc(sizeof(struct ListNode*));
    List1->next->next = (struct ListNode*)malloc(sizeof(struct ListNode*));
    List1->next->val = 1;
    List1->next->next->val = 1;
    struct ListNode* List2 = deleteDuplicates(List1);
    print_s(List2);
}