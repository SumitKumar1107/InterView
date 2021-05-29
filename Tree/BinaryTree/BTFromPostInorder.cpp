Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
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
     int postindex;
    //take explanation from notes and your mind
    TreeNode* helper(vector<int>&postorder,vector<int>&inorder,int is, int ie)
    {
        if(is>ie)
        return NULL;
        
        TreeNode* root = new TreeNode(postorder[postindex--]); //nodecreation
        
        int inindex;
        
        for(int i=is;i<=ie;i++)
        {
            if(inorder[i]==root->val)
            {
                inindex=i;
                break;
            }
        }
        
        root->right = helper(postorder,inorder,inindex+1,ie);
        root->left  = helper(postorder,inorder,is,inindex-1); //travel here in postorder way as we are building from postorder,we decrease index of postorder index whenever we create a new node. 
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postindex=inorder.size()-1;
        return helper(postorder,inorder,0,postorder.size()-1);
    }
};