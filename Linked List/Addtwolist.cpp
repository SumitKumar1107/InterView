You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* start = ans;
        int sum= 0;
        
        while(l1!=NULL || l2!=NULL)
        {
            sum /= 10;
            
            if(l1!=NULL)
            {
                sum += l1->val;
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                sum += l2->val;
                l2=l2->next;
            }
            ans->next = new ListNode(sum%10);
            ans = ans->next;
        }
        if(sum/10 == 1)
        {
            ans->next = new ListNode(1);
        }
        return start->next;
    }