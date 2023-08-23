//https://rb.gy/fkc54

#include <bits/stdc++.h> 
/*
    Following is the Binary Tree node structure:

    class BinaryTreeNode {
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
*/

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    BinaryTreeNode<int> * temp = root;
    while(temp){
        if(temp->data == x){
            return true;
        }
        else if(temp->data < x){
            temp = temp->right;
        }
        else{
            temp = temp->left;
        }
    }
    return false;
}
