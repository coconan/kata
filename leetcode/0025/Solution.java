// https://leetcode.com/problems/reverse-nodes-in-k-group/description/
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
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode newHead = head;
        ListNode prev = null;
        ListNode next = head;
        while (true) {
            ListNode start = next;
            ListNode end = start;
            for (int i = 0; i < k-1 && end != null; i++) {
                end = end.next;
            }
            if (end != null) {
                next = end.next;
                end.next = null;
                reverse(start);
                if (prev != null) {
                    prev.next = end;
                } else {
                    newHead = end;
                }
                prev = start;
                prev.next = next;
            } else {
                break;
            }
        }

        return newHead;
    }

    public ListNode reverse(ListNode head) {
        ListNode newHead = null;
        ListNode cur = head;
        while (cur != null) {
            ListNode temp = cur;
            cur = cur.next;
            temp.next = newHead;
            newHead = temp;
        }

        return newHead;
    }
}
