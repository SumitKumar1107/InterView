Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center)

Input: root = [1,2,2,3,4,4,3]
Output: true

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
    bool help(TreeNode* root1, TreeNode* root2)
    {
        if(root1 == NULL && root2 == NULL)
        return true;
        
        if(root1 == NULL || root2 == NULL)
        return false;
        
        if(root1 && root2 && root1->val == root2->val)
        return help(root1->left,root2->right) && help(root1->right,root2->left);
        
        return false;
    }
    
    bool isSymmetric(TreeNode* root) {
       return help(root,root);
    }
};