Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)
        return ans;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            int sz = q.size();
            vector<int>ans1;
            for(int i=0;i<sz;i++)
            {
                 TreeNode* p = q.front();
                q.pop();
                ans1.push_back(p->val);
                if(p->left)
                q.push(p->left);
                if(p->right)
                q.push(p->right);
            }
            ans.push_back(ans1);
        }
        return ans;
    }
};