Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root,vector<int>&v1,int &max,int level)
    {
       
        if(root==NULL)
            return;
        cout<<level<<" "<<max<<endl;
        if(level>max)
        {
            v1.push_back(root->val);
            max += 1;
        }
        solve(root->right,v1,max,level+1);
        solve(root->left,v1,max,level+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int>v;
        int count = 0;
        solve(root,v,count,1);
        return v;
    }
};