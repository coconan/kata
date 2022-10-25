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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        head = reverseLinkList(head);
        ListNode prev = null;
        ListNode target = head;
        for (int i = 1; i < n; i++) {
            prev = target;
            target = target.next;
        }
        if (prev == null) {
            head = target.next;
        } else {
            prev.next = target.next;
        }
        return reverseLinkList(head);
    }
    
    private ListNode reverseLinkList(ListNode head) {
        ListNode newHead = null;
        while (head != null) {
            ListNode tmp = head;
            head = tmp.next;
            tmp.next = newHead;
            newHead = tmp;
        }
        return newHead;
    }
}