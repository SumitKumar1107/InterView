Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument.

  1
 /  \
3    2
Output: 1 3

// A wrapper over leftViewUtil()
void Solve(Node* root, int level, vector<int>&v1, int *max)
{
    if(!root)
    return;

    if(level>*max)
    {
    //cout<<root->data<<" ";
    v1.push_back(root->data);
    *max = *max + 1;
    }

Solve(root->left,level+1,v1,max);
Solve(root->right,level+1,v1,max);
}

vector<int> leftView(Node *root)
{
   // Your code here
  // Your code here
    vector<int>v;
    int count = 0;
    Solve(root,1,v,&count);
    return v;
}