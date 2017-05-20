/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head = new ListNode(0), tail = head, last = null;
        boolean carry = false;
        while (carry || l1 != null || l2 != null) {
            int val = carry ? 1 : 0;
            if (l1 != null) {
                val += l1.val;
                l1 = l1.next;
            }
            if (l2 != null) {
                val += l2.val;
                l2 = l2.next;
            }
            carry = val >= 10;
            tail.val = val % 10;
            last = tail;
            tail = tail.next = new ListNode(0);
        }
        last.next = null;
        return head;
    }
}
