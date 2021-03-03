You are given a doubly linked list which in addition to the next and previous pointers, it could have a child pointer, which may or may not point to a separate doubly linked list. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure, as shown in the example below.

Flatten the list so that all the nodes appear in a single-level, doubly linked list. You are given the head of the first level of the list.


Input: head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
Output: [1,2,3,7,8,11,12,9,10,4,5,6]

 Node* flatten(Node* head) {
        //prev and child use for maintaining doubly linked list
        //child if it's have child or not
        
        for(Node*h = head;h;h=h->next) //iterating over all node
        {
            if(h->child) //if it's child then we will flatten it
            {
                Node *next = h->next; //getting next pointer of node
                h->next = h->child;   //making next pointer to child
                h->next->prev = h;    
                h->child=NULL;
                Node* p = h->next;
                while(p->next)
                {
                    p=p->next;
                }
                p->next = next;     //pointing next pointer of end child to next node
                if(next)
                {
                    next->prev=p;
                }
            }
        }
        return head;
    }
    
    /*lets say we start out with
h    
1 - 2 - 3 - 4 - 5 - null
    |
    6 - 7 - 8 - null
            |
            9 - 10 - null

h points to the head of the structure
horizontal links are bidirectional
vertical links indicate child relationship

after the first child is encountered:

        h
1 - 2 - 6 - 7 - 8 - 3 - 4 - 5 - null
                |
                9 - 10 - null

after the second child is encountered:

                    h
1 - 2 - 6 - 7 - 8 - 9 - 10 - 3 - 4 - 5 - null*/
};