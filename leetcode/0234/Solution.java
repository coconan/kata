// https://leetcode.com/problems/palindrome-linked-list/
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
    public boolean isPalindrome(ListNode head) {
        List<Integer> list = new ArrayList<>();
        while (head != null) {
            list.add(head.val);
            head = head.next;
        }
        int size = list.size();
        for (int i = 0, j = size -1; i < j; i++, j--) {
            if (list.get(i) != list.get(j)) {
                return false;
            }
        }

        return true;
    }
}

class Solution {
    public boolean isPalindrome(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        ListNode p = null;
        ListNode q = null;
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            ListNode n = slow.next;
            slow.next = p;
            p = slow;
            slow = n;
        }
        
        q = slow;
        if (fast != null) {
            q = q.next;
        }
        while (p != null && q != null) {
            if (p.val != q.val) {
                return false;
            }
            p = p.next;
            q = q.next;
        }

        return true;
    }
}
