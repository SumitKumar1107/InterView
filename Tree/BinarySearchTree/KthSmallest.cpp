Given the root of a binary search tree, and an integer k, return the kth (1-indexed) smallest element in the tree.

Input: root = [3,1,4,null,2], k = 1
Output: 1

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
    int ans;
    void check(TreeNode* root, int k , int &count)
    {
        if(root!=NULL)
        {
            check(root->left,k,count);
            count++;
            if(count==k)
            {
                ans = root->val;
            }
            check(root->right,k,count);
        }
    }
    
    int kthSmallest(TreeNode* root, int k) {
        
        int count = 0;
        check(root,k,count);
        return ans;
    }
};