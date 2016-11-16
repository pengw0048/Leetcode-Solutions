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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        if (lists.size() == 1) return lists[0];
        vector<ListNode*> tmp;
        for(int i=0;i<lists.size();i+=2){
            if(i+1==lists.size())tmp.push_back(lists[i]);
            else tmp.push_back(mergeTwoLists(lists[i],lists[i+1]));
        }
        return mergeKLists(tmp);
    }
    
};