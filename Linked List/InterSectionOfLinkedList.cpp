Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

1->1->8->4->4->5
5->6->8->4->4->5

Reference of the node with value = 8

  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        //not easy question
        //You can prove that: say A length = a + c, B length = b + c, after switching pointer, pointer A will move another b + c steps, pointer B will move a + c more steps, since a + c + b + c = b + c + a + c, it does not matter what value c is. Pointer A and B must meet after a + c + b (b + c + a) steps. If c == 0, they meet at NULL.
        
        if(headA==NULL || headB==NULL) return NULL;
        
        ListNode* a = headA;
        ListNode* b = headB;
        
        while(a!=b)
        {
            a = (a==NULL)?headB:a->next;
            b = (b==NULL)?headA:b->next;
        }
        return a;
    }
