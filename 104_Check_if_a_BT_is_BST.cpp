// https://rb.gy/qxs74

#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void solve(BinaryTreeNode<int> *root, vector<int> &v){
    if(root == NULL){
        return;
    }
   
    solve(root->left, v);
    v.push_back(root->data);
    solve(root->right,v);
}

bool validateBST(BinaryTreeNode<int> *root) {
    
    if(root == NULL){
        return true;
    }
    vector<int> v;
    solve(root, v);
    int flag = 0;
    for(int i=1; i<v.size(); i++){
        if(v[i-1] > v[i]){
            return false;
        }
    }
    return true;
}
