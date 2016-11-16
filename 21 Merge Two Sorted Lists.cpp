class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode head(0),*p=&head;
        while(l1||l2){
            if(!l1){p->next=l2;break;}
            if(!l2){p->next=l1;break;}
            if(l1->val<l2->val){
                p->next=l1;
                p=l1;
                l1=l1->next;
            }else{
                p->next=l2;
                p=l2;
                l2=l2->next;
            }
        }
        return head.next;
    }
};