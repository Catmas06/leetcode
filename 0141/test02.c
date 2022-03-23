/*
    使用哈希表
    还不会用:)
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
    //将struct ListNode 的指针作为对比的 key值，可以有多个key值
    struct ListNode *key;
    //表示该结构体是哈希表类型
    UT_hash_handle hh;
};

//使用前必须定义哈希表的指针并赋值NULL，可以在调用前再赋值
struct hashTable *hashtable;

//自定义查找函数
struct hashTable *find(struct ListNode *ikey)
{
    struct hashTable *tmp;
    HASH_FIND_PTR(hashtable, &ikey, tmp);
    return tmp;
}

//自定义添加函数
void insert(struct ListNode *ikey)
{
    struct hashTable *tmp = malloc(sizeof(struct hashTable));
    tmp->key = ikey;
    HASH_ADD_PTR(hashtable, key, tmp);
}

bool hasCycle(struct ListNode *head)
{
    hashtable = NULL;
    while (head != NULL)
    {
        if (find(head) != NULL)
        {
            return true;
        }
        insert(head);
        head = head->next;
    }
    return false;
}