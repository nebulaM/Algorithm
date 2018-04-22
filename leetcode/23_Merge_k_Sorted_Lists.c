/**
 * Merge k sorted linked lists and return it as one sorted list.
 * Analyze and describe its complexity.
 * Input:
 * [
 *  1->4->5,
 *  1->3->4,
 *  2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;

ListNode* merge2Lists(ListNode *l1, ListNode *l2);

ListNode* mergeKLists(ListNode **lists, int listsSize) {
    int i;
    int interval = 1;

    if(listsSize <= 0)
    {
        return NULL;
    }

    while(interval < listsSize)
    {
        for(i = 0; i < listsSize - interval; i += (interval << 1))
            lists[i] = merge2Lists(lists[i], lists[i + interval]);
        interval <<= 1;
    }

    return lists[0];
}

ListNode* merge2Lists(ListNode *l1, ListNode *l2)
{
    ListNode  head;
    ListNode *temp = &head;

    while(l1 && l2)
    {
        if(l1->val > l2->val)
        {
            temp->next = l2;
            l2 = l1;
            l1 = temp->next->next;
        }
        else
        {
            temp->next = l1;
            l1 = l1->next;
        }

        temp = temp->next;
    }

    if(l1)
        temp->next = l1;
    else
        temp->next = l2;

    return head.next;
}