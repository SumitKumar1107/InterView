Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) { 
        //use bfs to traverse and point next to right node
        if(root==NULL)
        return root;
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                auto p = q.front();
                q.pop();
                
                if(i!=sz-1)
                p->next = q.front();
                
                if(p->left)
                q.push(p->left);
                if(p->right)
                q.push(p->right);
            }
        }
        return root;
    }
};