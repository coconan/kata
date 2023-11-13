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

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode result = null;
        ListNode cur = null;
        int min = 10000+1;
        int minIndex = -1;
        do {
            min = 10000+1;
            minIndex = -1;
            for (int i = 0; i < lists.length; i++) {
                if (lists[i] != null && lists[i].val <= min) {
                    min = lists[i].val;
                    minIndex = i;
                }
            }
            if (minIndex >= 0) {
                if (result == null) {
                    result = lists[minIndex];
                    cur = lists[minIndex];
                } else {
                    cur.next = lists[minIndex];
                    cur = lists[minIndex];   
                }
                lists[minIndex] = lists[minIndex].next;
                cur.next = null;
            }
        } while (minIndex >= 0);

        return result;
    }
}

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0) {
            return null;
        }
        return doMerge(lists, 0, lists.length-1);
    }

    public ListNode doMerge(ListNode[] lists, int left, int right) {
        if (left == right) {
            return lists[left];
        }

        int mid = (left + right) / 2;
        ListNode a = doMerge(lists, left, mid);
        ListNode b = doMerge(lists, mid+1, right);
        return mergeTwoList(a, b);
    }

    public ListNode mergeTwoList(ListNode a, ListNode b) {
        if (a == null || b == null) {
            return a == null ? b : a;
        }

        ListNode result = null;
        ListNode cur = null;
        ListNode minNode = null;
        while (a != null && b != null) {
            if (a.val < b.val) {
                minNode = a;
                a = a.next;
            } else {
                minNode = b;
                b = b.next;
            }
            
            if (result == null) {
                result = minNode;
                cur = minNode;
            } else {
                cur.next = minNode;
                cur = minNode;
            }
            cur.next = null;
        }

        if (a != null) {
            cur.next = a;
        }
        if (b != null) {
            cur.next = b;
        }

        return result;
    }
}

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0) {
            return null;
        }
        return doMerge(lists, 0, lists.length-1);
    }

    public ListNode doMerge(ListNode[] lists, int left, int right) {
        if (left == right) {
            return lists[left];
        }

        int mid = (left + right) / 2;
        ListNode a = doMerge(lists, left, mid);
        ListNode b = doMerge(lists, mid+1, right);
        return mergeTwoList(a, b);
    }

    public ListNode mergeTwoList(ListNode a, ListNode b) {
        if (a == null || b == null) {
            return a == null ? b : a;
        }
        
        if (a.val < b.val) {
            a.next = mergeTwoList(a.next, b);
            return a;
        } else {
            b.next = mergeTwoList(a, b.next);
            return b;
        }
    }
}
