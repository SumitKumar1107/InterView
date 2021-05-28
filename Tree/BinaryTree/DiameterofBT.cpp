Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3is the length of the path [4,2,1,3] or [5,2,1,3].


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int height(TreeNode* node) 
{  
   if(node == NULL) 
       return 0; 
    
   return 1 + max(height(node->left), height(node->right)); 
}  

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
     
        if(root == NULL)
            return 0;
        
        int lheight = height(root->left);
        int rheight = height(root->right);
        int ldiam = diameterOfBinaryTree(root->left);
        int rdiam = diameterOfBinaryTree(root->right);
        
        int fd = max(lheight+rheight,max(ldiam,rdiam));
        
        return fd;
    }
};