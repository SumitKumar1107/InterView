Given the head of a linked list, rotate the list to the right by k places.

Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]


ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
            return NULL;
        
        int len=1;
        ListNode *newh,*tail;
        newh=tail=head;
        
        while(tail->next!=NULL)
        {
            tail = tail->next;
            len++;
        }
        tail->next = head; //connect last node to first
        
        if(k=k%len)
        {
            for(int i=0;i<len-k;i++) //for rotation we have to loop len-k times and then change pointers to get answer
            {
                tail = tail->next;
            }
        }
        newh = tail->next;
        tail->next = NULL;
        return newh;
    }