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
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        int i;
        int interval = 1;
        
        if(lists.length <= 0)
        {
            return null;
        }
        
        while(interval < lists.length)
        {
            for(i = 0; i < lists.length - interval; i += (interval << 1))
                lists[i] = merge2Lists(lists[i], lists[i + interval]);
            interval <<= 1;
        }
        
        return lists[0];
    }
    
    public ListNode merge2Lists(ListNode l1, ListNode l2)
    {
        ListNode head = new ListNode(0);
        ListNode temp = head;
        
        while(l1 != null && l2 != null)
        {
            if(l1.val > l2.val)
            {
                temp.next = l2;
                l2 = l1;
                l1 = temp.next.next;
            }
            else
            {
                temp.next = l1;
                l1 = l1.next;
            }

            temp = temp.next;
        }
        
        if(l1 != null)
            temp.next = l1;
        else
            temp.next = l2;
            
        return head.next;
    }
}