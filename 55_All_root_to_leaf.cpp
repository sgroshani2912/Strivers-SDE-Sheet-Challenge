// https://rb.gy/mx9iy

#include <bits/stdc++.h> 
/********************************************************************

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
    
********************************************************************/
void solve(BinaryTreeNode < int > * root, string s, vector<string> &ans){
    if(root == NULL){
        return;
    }

    s += to_string(root->data)+" ";
    if(!root->left && !root->right){
        ans.push_back(s);
        return ;
    }

    
    solve(root->left, s, ans);
    solve(root->right, s, ans);
}

vector < string > allRootToLeaf(BinaryTreeNode < int > * root) {
    vector<string> ans;
    if(root == NULL){
        return ans;
    }

    solve(root, "", ans);
    return ans;
}
