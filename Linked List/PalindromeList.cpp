Given a singly linked list, determine if it is a palindrome.

Input: 1->2
Output: false

ListNode* reverse(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while(curr!=NULL)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head==NULL)
            return true;
        //find the second half and reverse it and then compare first half and reversed second half
        
        ListNode* slow = head, *fast=head;
        
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* rev  = reverse(slow->next);
        ListNode* curr = head;
        
        while(rev!=NULL)
        {
            if(rev->val!=curr->val)
                return false;
            
            rev=rev->next;
            curr=curr->next;
        }
        return true;
    }