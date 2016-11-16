class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool carry = false;
        ListNode *ret = NULL, **tail = &ret;
        while (carry || l1 || l2) {
            int val = carry;
            if (l1) {
                val += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                val += l2->val;
                l2 = l2->next;
            }
            carry = val >= 10;
            ListNode *tmp = new ListNode(val % 10);
            *tail = tmp;
            tail = &(tmp->next);
        }
        return ret;
    }
};