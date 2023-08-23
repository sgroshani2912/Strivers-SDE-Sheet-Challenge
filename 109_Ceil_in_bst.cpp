// https://rb.gy/qchms

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/
void find(BinaryTreeNode<int> * root, int X, int &ans){
    if(root == NULL){
        return ;
    }

    if(root->data == X){
        ans = X;
    }
    else if(root->data > X){
        ans = min(ans, root->data);
        find(root->left, X, ans);
        
    }
    else{
        find(root->right, X, ans);
    }
    
}

int findCeil(BinaryTreeNode<int> *node, int x){
    int ans = INT_MAX;
    find(node, x, ans);
    if(ans == INT_MAX){
        return -1;
    }
    return ans;
}
