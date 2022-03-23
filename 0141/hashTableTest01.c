/*
    hash的使用
        1、创建hashTable结构体，每个结构体用以存储哈希表中的一个数据，key即为想要存储的具体类型
*/
#include <uthash.h>
#include <stdbool.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct hashTable
{
    struct ListNode *key;
    UT_hash_handle hh;
} * hashTable;

struct hashTable *find(struct ListNode *ikey)
{
    struct hashTable *tmp;
    HASH_FIND_PTR(hashTable, &ikey, tmp);
    return tmp;
};

void insert(struct ListNode *ikey)
{
    struct hashTable *tmp = malloc(sizeof(struct hashTable));
    tmp->key = ikey;
    HASH_ADD_PTR(hashTable, key, tmp);
}

bool hasCycle(struct ListNode *head)
{
    hashTable = NULL;
    while (head)
    {
        if (find(head))
            return true;
        insert(head);
        head = head->next;
    }
    return false;
}

int main()
{
    struct ListNode *l1 = malloc(sizeof(struct ListNode));
    struct ListNode *l2 = malloc(sizeof(struct ListNode));
    struct ListNode *l3 = malloc(sizeof(struct ListNode));
    struct ListNode *l4 = malloc(sizeof(struct ListNode));
    struct ListNode *l5 = malloc(sizeof(struct ListNode));
    l1->val = 1;
    l2->val = 2;
    l3->val = 3;
    l4->val = 4;
    l5->val = 5;
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l3;
    hasCycle(l1);
    return 0;
}