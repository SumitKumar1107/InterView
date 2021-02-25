Given a non-empty, singly linked list with head node head, return a middle node of linked list.

If there are two middle nodes, return the second middle node.

Input: [1,2,3,4,5]
Output: Node 3 from this list (Serialization: [3,4,5])
The returned node has value 3.  (The judge's serialization of this node is [3,4,5]).
Note that we returned a ListNode object ans, such that:
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, and ans.next.next.next = NULL.


 ListNode* middleNode(ListNode* head) {
        ListNode* p = head;
        ListNode* q = head;
        
        while(q!=NULL && q->next!=NULL)
        {
            p = p->next;
            q = q->next->next;
        }
        return p;
    }