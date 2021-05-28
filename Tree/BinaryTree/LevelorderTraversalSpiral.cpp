Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)
        return ans;
        
        queue<TreeNode*>q;
        q.push(root);
        bool rev = false;
        stack<int>st;
        
        while(!q.empty())
        {
            vector<int>ans1;
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode* p = q.front();
                q.pop();
                
                if(rev==false)
                {
                    ans1.push_back(p->val);
                }
                else
                {
                    st.push(p->val);
                }
                
                if(p->left)
                q.push(p->left);
                if(p->right)
                q.push(p->right);
            }
            if(rev==false)
            ans.push_back(ans1);
            else
            {
                vector<int>ans2;
                
                while(!st.empty())
                {
                    int a = st.top();
                    ans2.push_back(a);
                    st.pop();
                }
                ans.push_back(ans2);
            }
            rev = !rev;
        }
        return ans;
    }
};