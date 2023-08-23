// https://rb.gy/utwks

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
TreeNode<int>* solve(TreeNode<int>* root, int a, int b){
    if(root == NULL){
        return NULL;
    }

    if(root->data < a && root->data < b){
        return solve(root->right, a, b);
    }

    if(root->data > a && root->data >b ){
        return solve(root->left,a ,b);
    }
    return root;
}

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	int a = P->data;
    int b = Q->data;

    TreeNode<int>* ans = solve(root, a, b );
    return ans;

    
}
