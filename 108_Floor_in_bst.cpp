// https://rb.gy/lj9hs

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void find(TreeNode<int> * root, int X, int &ans){
    if(root == NULL){
        return ;
    }

    if(root->val == X){
        ans = X;
    }
    else if(root->val > X){
        find(root->left, X, ans);
    }
    else{
        ans = max(ans, root->val);
        find(root->right, X, ans);
    }
    
    
}

int floorInBST(TreeNode<int> * root, int X)
{
    int ans = -1;
    find(root, X, ans);
    return ans;
    
}
