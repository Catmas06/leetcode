/*
    使用哈希表
    还不会用:)
*/

struct hashTable
{
    struct ListNode *key;
    UT_hash_handle hh;
};

struct hashTable *hashtable;

struct hashTable *find(struct ListNode *ikey)
{
    struct hashTable *tmp;
    HASH_FIND_PTR(hashtable, &ikey, tmp);
    return tmp;
}

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

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/linked-list-cycle/solution/huan-xing-lian-biao-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。