// http://rb.gy/ok6le

#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
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
void solve_leaf(TreeNode<int>* root, vector<int> &ans){
    if(root==NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
        return;
    }

    solve_leaf(root->left, ans);
    solve_leaf(root->right, ans);

}

void solve_left(TreeNode<int>* root, vector<int> &ans){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL ){
        return;
    }

    ans.push_back(root->data);

    if(root->left){
        solve_left(root->left, ans);
    }
    else{
        solve_left(root->right, ans);
    }
}

void solve_right(TreeNode<int>* root, vector<int> &ans){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        return;
    }

    if(root->right){
        solve_right(root->right, ans);
    }
    else{
        solve_right(root->left, ans);
    }
    ans.push_back(root->data);

}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> ans;
    if(root == NULL) return ans;

    ans.push_back(root->data);

    //Left part traversal
    solve_left(root->left, ans);

    //Leaf Node traversal from left to right
    solve_leaf(root->left, ans);
    solve_leaf(root->right, ans);

    //Right part traversal
    solve_right(root->right, ans);

    return ans;
}
