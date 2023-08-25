// https://rb.gy/0ti0v

#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void solve(TreeNode<int>* root, int &k, int &result){
    if(root == NULL){
        return;
    }
    solve(root->right, k, result);
    k--;
    if(k==0){
        result = root->data;
    }
    solve(root->left, k, result);
}
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    int result =-1;
    solve(root, k, result);
    if(result == -1){
        return -1;
    }
    return result;
}
