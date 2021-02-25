Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.

1->2->4

1->3->4

output : 1->2->3->4

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        
        ListNode* head=NULL;
        ListNode* tail=NULL;
        
        if(l1->val<=l2->val)
        {
            head=tail=l1;
            l1=l1->next;
        }
        else
        {
            head=tail=l2;
            l2=l2->next;
        }
        
        while(l1!=NULL && l2!=NULL)
        {
            if(l1->val <= l2->val)
            {
                tail->next = l1;
                tail=l1;
                l1=l1->next;
            }
            else
            {
                tail->next = l2;
                tail=l2;
                l2=l2->next;
            }
        }
        
        if(l1==NULL)
        {
            tail->next = l2;
        }
        else
        {
            tail->next = l1;
        }
        return head;
    }

