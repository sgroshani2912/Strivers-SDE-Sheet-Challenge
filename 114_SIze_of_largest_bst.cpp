// https://rb.gy/ab00r

#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
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
class info{
    public:
    bool is_bst;
    int maxi;
    int mini;
    int size;
};

info solve(TreeNode<int>* root, int &max_ans){
    if(root == NULL){
        return {true, INT_MIN, INT_MAX, 0};
    }
    
    info left_ans = solve(root->left, max_ans);
    info right_ans = solve(root->right, max_ans);

    info curr_ans;
    curr_ans.size = left_ans.size + right_ans.size + 1;
    curr_ans.maxi = max(root->data, right_ans.maxi);
    curr_ans.mini = min(root->data, left_ans.mini);
    
    if(left_ans.is_bst && right_ans.is_bst && root->data > left_ans.maxi && root->data < right_ans.mini){
        curr_ans.is_bst = true;
    }
    else{
        curr_ans.is_bst = false;
    }

    if(curr_ans.is_bst){
        max_ans = max(curr_ans.size, max_ans);
    }

    return curr_ans;
}

int largestBST(TreeNode<int>* root) 
{
    int max_ans = 0;
    
    info ans = solve(root, max_ans);

    return max_ans;
}
