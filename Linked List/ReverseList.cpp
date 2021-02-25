Given the head of a singly linked list, reverse the list, and return the reversed list.

1->2->3->4->5

5->4->3->2->1

ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while(curr!=NULL)
        {
            ListNode* next = curr->next; //1->2->3->4->->NULL
            curr->next     = prev;
            prev           = curr;
            curr           = next; 
        }
        return prev;
    }