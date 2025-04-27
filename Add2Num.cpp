
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp=new ListNode();
        ListNode*head=temp;
        int cnt=0;
        while(l1!=NULL || l2!=NULL || cnt){
            int ans=0;
            if(l1!=NULL){
                ans+=l1->val;l1=l1->next;
            }
            if(l2!=NULL){
                ans+=l2->val;l2=l2->next;
            }
            ans+=cnt;
            cnt=ans/10;
            ListNode* newly=new ListNode(ans%10);
            head->next=newly;
            head=head->next;
        }
        return temp->next;
    }
