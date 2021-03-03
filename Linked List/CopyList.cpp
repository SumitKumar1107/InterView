A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

Node* copyRandomList(Node* head) {
     //three step to solve this problem 
        
    //step 1 -  make copy of each node and link them together side-by-side in a single list.
        
        Node * iter = head , *front = head;
        
        while(iter!=NULL)
        {
            front = iter->next;
            Node *copy = new Node(iter->val);
            iter->next = copy;
            copy->next = front;
            iter=front;
        }
        
        //step 2 - assign random pointers for the copy nodes.
        
        iter = head;
        while(iter!=NULL)
        {
            if(iter->random!=NULL)
            iter->next->random = iter->random->next;
            
            iter=iter->next->next;
        }
        
        //step 3 -  restore the original list, and extract the copy list.
        
        Node *psuedohead = new Node(0);
        Node *copy = psuedohead;
        
        iter = head;
        while(iter!=NULL)
        {
            front = iter->next->next;
            copy->next = iter->next;
            iter->next = front;
            copy = copy->next;
            iter = front;
        }
        return psuedohead->next;
    }