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
    public ListNode swapPairs(ListNode head) {
        ListNode current = head, next = null, prev = null;
        if (current != null && current.next != null) {
            head = current.next;
        }
        while (true) {
            if (current == null || current.next == null) {
                break;
            }
            next = current.next;
            current.next = current.next.next;
            next.next = current;
            if (prev != null) {
                prev.next = next;
            }
            
            prev = current;
            current = current.next;
        }
        return head;
    }
}