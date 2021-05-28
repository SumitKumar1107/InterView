Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if(root == NULL)
    {
        return NULL;
    }
    if(root->val == p->val || root->val == q->val)
    {
        return root;
    }
    struct TreeNode* left = lowestCommonAncestor(root->left,p,q);
    struct TreeNode* right = lowestCommonAncestor(root->right,p,q);
    
    if(left!=NULL && right!=NULL)
    {
        return root;
    }
    else
    {
      return left!=NULL?left:right;  
    }  
    
    //https://www.youtube.com/watch?v=13m9ZCB8gjw&t=657s
}