/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if(head == null || head.next == null)
            return head;
   
        int n = 0;
        ListNode temp = head;
        while(temp != null){
            n++;
            temp = temp.next;
        }
         if(k == n){
            return head;
        }
        if(k > n)
        {
            k = k%n;
        }
        if(k == 0)
            return head;
        
        int remains = n - k;
        temp = head;
        while(--remains > 0){
            temp = temp.next;
        }
        ListNode sec = temp.next;
        ListNode result = sec;
        temp.next = null;
        while(sec.next != null){
            sec = sec.next;
        }
        sec.next = head;
        return result;
    }
}
