Given a Binary search tree. Your task is to complete the function which will return the Kth largest element without doing any modification in Binary Search Tree.

Input:
      4
    /   \
   2     9
k = 2 
Output: 4

class Solution
{
    public:
    int ans;
    
    void check(Node* root, int k,int &count)
    {
        if(root!=NULL)
        {
            check(root->right,k,count);
            count++;
            if(count==k)
            ans = root->data;
            
            check(root->left,k,count);
        }
    }
    
    int kthLargest(Node *root, int K)
    {
        int count = 0;
        check(root, K,count);
        return ans;
    }
};