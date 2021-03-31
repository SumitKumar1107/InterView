The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.

int solve(TreeNode* root, map<TreeNode*,int>&mp)
    {
        if(root==NULL)
            return 0;
        
        if(mp.find(root)!=mp.end())
            return mp[root];
        
        int val = 0;
        
        if(root->left!=NULL)
        {
            val += solve(root->left->left,mp)+solve(root->left->right,mp);
        }
        if(root->right!=NULL)
        {
            val += solve(root->right->left,mp)+solve(root->right->right,mp);
        }
        val = max(val+root->val,solve(root->left,mp)+solve(root->right,mp));
        mp[root]=val;
        return val;
    }
        
    
    int rob(TreeNode* root) {
        map<TreeNode*,int>mp;
        
        return solve(root,mp);
    }