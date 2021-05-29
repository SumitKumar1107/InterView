Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL. The order of nodes in DLL must be same as Inorder of the given Binary Tree. The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.

Input:
      1
    /  \
   3    2
Output:
3 1 2 
2 1 3 
Explanation: DLL would be 3<=>1<=>2

Node *helper(Node *root,Node *&prev)
{
     
    if(root==NULL)
    return NULL;
    
    Node*head = helper(root->left,prev);
    if(prev==NULL)
    {
        head = root;
    }
    else
    {
        root->left=prev;
        prev->right=root;
    }
    prev=root;
    helper(root->right,prev);
    return head;
}
Node * bToDLL(Node *root)
{
    // your code here
    Node* head = NULL; 
    return helper(root,head);
}