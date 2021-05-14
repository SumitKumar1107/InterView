Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

     1
   /    \
  2      3
Output: 2 1 3

       10
    /      \
  20        30
 /   \    /    \
40   60  90    100
Output: 40 20 10 30 100

// function should print the topView of the binary tree
vector<int> topView(struct Node *root)
{
    //Your code here
    vector<int>ans;
    if(!root)
    return ans;
    
    map<int,vector<int>>mp;
    int hd = 0;
    
    queue<pair<Node*, int> > que;
    que.push(make_pair(root, hd));
    
    while(!que.empty())
    {
        pair<Node*, int> temp = que.front();
        que.pop();
        hd = temp.second;
        Node* node = temp.first;
 
        // insert this node's data in vector of hash , first time it's coming 
        if(mp.find(hd)==mp.end())
        mp[hd].push_back(node->data);
 
        if (node->left != NULL)
            que.push(make_pair(node->left, hd - 1));
        if (node->right != NULL)
            que.push(make_pair(node->right, hd + 1));
    }
    
    for(auto m: mp)
    {
        for(auto x:m.second)
        {
            ans.push_back(x);
        }
    }
    return ans;
}