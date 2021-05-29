Share
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Input: root = [2,1,3]
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
    
    bool check(TreeNode* root, long mn , long mx)
    {
        if(root==NULL)
            return true;
        
        if(root->val >= mx || root->val <= mn)
            return false;
        
        return check(root->left,mn,root->val) && check(root->right,root->val,mx);
    }
    
    bool isValidBST(TreeNode* root) {
        
        long mn = LONG_MIN;
        long mx = LONG_MAX;
        return check(root,mn,mx);
    }
};