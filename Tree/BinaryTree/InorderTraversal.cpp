Given the root of a binary tree, return the inorder traversal of its nodes' values.

Input: root = [1,null,2,3]
Output: [1,3,2]

Order : Left Root Right

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
    //see YaoFrankie visual explanation

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>s;//storing root & left part
        
        TreeNode* curr = root;
        
        while(curr!=NULL||s.empty()==false) 
        {
            while(curr!=NULL)
            {
                s.push(curr);
                curr=curr->left;
            }
            
            curr = s.top();
            ans.push_back(curr->val);
            s.pop();
            curr=curr->right;
        }
        return ans;
    }
};