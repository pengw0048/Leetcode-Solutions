/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    bool carry = false;
    struct ListNode *ret = NULL, **tail = &ret;
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
        struct ListNode *tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
        tmp -> val = val % 10;
        tmp -> next = NULL;
        *tail = tmp;
        tail = &(tmp->next);
    }
    return ret;
}
