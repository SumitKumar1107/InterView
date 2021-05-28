Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

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
    int maxDepth(TreeNode* root) {
        if(root==NULL)
        return 0;
        queue<TreeNode*>q;
        q.push(root);
        
        int ans = 0; //how many level it traversed
        
        while(!q.empty())
        {
            ans++;
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                auto p = q.front();
                q.pop();
                
                if(p->left) q.push(p->left);
                if(p->right)q.push(p->right);
            }
        }
        return ans;
    }
};