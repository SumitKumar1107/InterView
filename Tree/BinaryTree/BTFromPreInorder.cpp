Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

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
    int preindex = 0;
    //take explanation from notes and your mind
    TreeNode* helper(vector<int>&preorder,vector<int>&inorder,int is, int ie)
    {
        if(is>ie)
        return NULL;
        
        TreeNode* root = new TreeNode(preorder[preindex++]); //nodecreation
        
        int inindex;
        
        for(int i=is;i<=ie;i++)
        {
            if(inorder[i]==root->val)
            {
                inindex=i;
                break;
            }
        }
        
        root->left  = helper(preorder,inorder,is,inindex-1);
        root->right = helper(preorder,inorder,inindex+1,ie);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder,inorder,0,preorder.size()-1);
    }
};