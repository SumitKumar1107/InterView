Given the root of a binary tree, return the postorder traversal of its nodes' values.

Input: root = [1,null,2,3]
Output: [3,2,1]

Order : left right root

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode* last = NULL;
        stack<TreeNode*>st;
        
        while(root || !st.empty())
        {
            if(root)
            {
                st.push(root);
                root=root->left;
            }
            else
            {
                TreeNode* node = st.top();
                if(node->right && last!=node->right)
                {
                    root = node->right;
                }
                else
                {
                    ans.push_back(node->val);
                    last = node;
                    st.pop();
                }
            }
        }
        return ans;
    }
};