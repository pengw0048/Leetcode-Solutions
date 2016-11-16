class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (k == 1)return head;
		ListNode first(-1),**p=&(first.next);
		while (head) {
			ListNode *ps = head, *pf = head, *pn = head->next, *pt = pn, *pp = head;
			for (int i = 0; i < k; i++) {
				if (!pp) {
					*p = head;
					return first.next;
				}
				pp = pp->next;
			}
			for (int i = 1; i < k; i++) {
				if (!pn)break;
				pt = pn->next;
				pn->next = pf;
				pf = pn;
				pn = pt;
			}
			head = pt;
			ps->next = NULL;
			*p = pf;
			p = &(ps->next);
		}
		return first.next;
	};
    ListNode* swapPairs(ListNode* head) {
        return reverseKGroup(head,2);
    }
};