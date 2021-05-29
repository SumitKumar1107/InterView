There is BST given with root node with key part as integer only. You need to find the inorder successor and predecessor of a given key. In case, if the either of predecessor or successor is not found print -1.


Input:
2
6
50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R
65
6
50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R
100

Output:
60 70
80 -1

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if(root==NULL)
    return;
    
    if(root->key==key)
    {
        if(root->right)
        {
            suc = root->right; //just greater element
            while(suc->left)
            suc=suc->left;
        }
        if(root->left)
        {
            pre = root->left;  //just smaller element
            while(pre->right)
            {
                pre=pre->right;
            }
        }
    }
    else if(root->key>key)    //successor
    {
        suc=root;
        findPreSuc(root->left,pre,suc,key);
    }
    else
    {
        pre=root;
        findPreSuc(root->right,pre,suc,key);
    }
}