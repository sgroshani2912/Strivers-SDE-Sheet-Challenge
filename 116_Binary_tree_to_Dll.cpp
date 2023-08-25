// https://rb.gy/ia0oh

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
void solve(BinaryTreeNode<int>* root, BinaryTreeNode<int>* &head, BinaryTreeNode<int>* &prev, int &flag){
    if(root == NULL){
        return;
    }
    solve(root->left, head, prev, flag);
    if(flag == 0){
        head = root;
        prev = root;
        flag = 1;
    }
    else{
        prev->right = root;
        prev->right->left = prev;
        prev = prev->right;
    }
    solve(root->right, head, prev, flag);
}

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    if(root == NULL){
        return NULL;
    }
    BinaryTreeNode<int>* head = NULL;
    BinaryTreeNode<int>* prev = NULL;
    int flag = 0;
    solve(root, head, prev, flag);
    return head;
}
