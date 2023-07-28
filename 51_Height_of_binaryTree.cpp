// http://rb.gy/f4siw

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
int solve(TreeNode<int> *root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return 0;
    }

    int left = solve(root->left);
    int right = solve(root->right);

    return 1 + max(left, right);
}

int maxDepth(TreeNode<int> *root) {
    int ans = solve(root);
    return ans;
}
