Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

Follow up:

Could you solve the problem in O(1) extra memory space?
You may not alter the values in the list's nodes, only nodes itself may be changed.

Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

 ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k==1)
            return head;
        // 1->2->3->4->5->6->7->8->->NULL
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        
        // 0->1->2->3->4->5->6->7->8->->NULL
        
        ListNode *pre = dummy , *cur = dummy , *nex = dummy; // all are pointing to zero
        int count = 0;
        
        while(cur->next!=NULL)
        {
            cur=cur->next;
            count++;
        }
        
        //our logic is to transform reverse one by one means 1<-2 then 2<-3
        
        while(count>=k)
        {
            cur = pre->next; //pointing to 1
            nex  = cur->next; //pointing to 2
            
            for(int i=1;i<k;i++)
            {
                cur->next = nex->next; //pointing to 3
                nex->next  = pre->next; //2 pointing towards 1 basically it's reversed
                pre->next = nex; //prev pointing towards to 2
                nex = cur->next; //pointing to 3;
            }
            pre = cur; // it take the last node of previous part and set to pre so 1 point to 6 which is desired
            count -=k;
        }
        return dummy->next;
    }