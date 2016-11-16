class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *a=head,**b=&head;
        while(n-->0)a=a->next;
        while(a){a=a->next;b=&((*b)->next);}
        *b=(*b)->next;
        return head;
    }
};