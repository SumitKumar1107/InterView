Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.


Input: root = [5,3,6,2,4,null,7], k = 9
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
    bool isPairSum(TreeNode *root, int sum, unordered_set<int> &s) 
    { 
        if(root==NULL)return false;
        
        if(isPairSum(root->left,sum,s)==true)
            return true;
            
        if(s.find(sum-root->val)!=s.end())  
            return true;
        else
            s.insert(root->val);
        return isPairSum(root->right,sum,s);
    } 
    
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return isPairSum(root,k,s);
    }
};