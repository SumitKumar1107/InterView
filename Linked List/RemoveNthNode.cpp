Given the head of a linked list, remove the nth node from the end of the list and return its head.

Follow up: Could you do this in one pass?

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

 ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* start = new ListNode(); //here we have to create dummy node because if there is one node then to skip we have to return null node so have to create dummy node and dummy node have zero value
        start->next = head;
        
        ListNode* slow = start;
        ListNode* fast = start;
        
        for(int i=1;i<=n;i++)
        {
            fast = fast->next;
        }
        
        while(fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return start->next;
    }