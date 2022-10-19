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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode result =null, current = null;
        int carry = 0, val = 0;
        do {
            val = (l1 == null ? 0 : l1.val) + (l2 ==null ? 0 : l2.val) + carry;
            carry = val / 10;
            val = val % 10;
            if (current == null) {
                current = new ListNode(val);
                result = current;
            } else {
                current.next = new ListNode(val);
                current = current.next;
            }
            if (l1 != null) {
                l1 = l1.next;
            }
            if (l2 != null) {
                l2 = l2.next;
            }
        } while (l1 != null || l2 != null || carry != 0);
        return result;
    }
}