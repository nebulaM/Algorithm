/**
 * Given a list, rotate the list to the right by k places, where k is non-negative.
 * For example:
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 // inspired by top c++ solution at https://leetcode.com/problems/rotate-list/
struct ListNode* rotateRight(struct ListNode* head, int k) {
  if(!head || !head->next){
    return head;
  }
  struct ListNode* tail=head;
  //already have at least one node
  int size=1;
  while(tail->next){
    tail=tail->next;
    size++;
  }
  tail->next=head;
  int rotate=size-(k%size);
  while(rotate){
    tail=tail->next;
    rotate--;
  }
  head=tail->next;
  tail->next=NULL;
  return head;

}
