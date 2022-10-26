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
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode result = null, tail = null, temp = null;
        while (true) {
            ListNode minNode = null;
            int minIndex = -1;
            for (int i = 0; i < lists.length; i++) {
                if (minNode == null && lists[i] != null) {
                    minNode = lists[i];
                    minIndex = i;
                }
                if (minNode != null && lists[i] != null && minNode.val > lists[i].val) {
                    minNode = lists[i];
                    minIndex = i;
                }
            }
            if (minNode == null) {
                break;
            }
            if (result == null) {
                result = minNode;
            }
            if (tail == null) {
                tail = minNode;
            } else {
                tail.next = minNode;
                tail = minNode;
            }
            lists[minIndex] = lists[minIndex].next;
            tail.next = null;
        }
        return result;
    }
}