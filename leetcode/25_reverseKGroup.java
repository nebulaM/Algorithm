/**
 * Example:
 * Given this linked list: 1->2->3->4->5
 * For k = 2, you should return: 2->1->4->3->5
 * For k = 3, you should return: 3->2->1->4->5
 */

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        if(head==null || head.next==null || k==0 || k==1){
            return head;
        }
        int size=0;
        ListNode tmp=head;
        while(tmp!=null){
            tmp=tmp.next;
            size++;
        }
        if(k>size){
            return head;
        }
        tmp=head;
        for(int i=0;i<(size-size%k);i++){
            tmp=tmp.next;
        }
        return reverseKNodes(head,k,size/k,tmp);
    }
    private ListNode reverseKNodes(ListNode head, int k, int repeat, ListNode remain){
        ListNode nextNewHead=null;
        if(repeat>1){
            int tmp=k;
            ListNode newHead=head;
            while(tmp>0){
                newHead=newHead.next;
                tmp--;
            }
            nextNewHead=reverseKNodes(newHead,k,repeat-1,remain);
        }
        ListNode prev=null,curr=head,next;
        while(k>0)
        {
            next=curr.next;
            curr.next=prev;
            prev=curr;
            curr=next;
            k--;
        }
        if(repeat==1){
            head.next=remain;       
        }else{
            head.next=nextNewHead;
        }
        return prev;
    }
}