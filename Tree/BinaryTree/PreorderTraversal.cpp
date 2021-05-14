Given the root of a binary tree, return the preorder traversal of its nodes' values.

Input: root = [1,null,2,3]
Output: [1,2,3]

Order: Root Left Right

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
    //see exp of jianchao-li
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>st;//storing right part of node
        
        while(root || !st.empty())
        {
            if(root)
            {
                ans.push_back(root->val);
                if(root->right)
                st.push(root->right);
                root=root->left;
            }
            else
            {
                root = st.top();
                st.pop();
            }
        }
        return ans;
    }
};