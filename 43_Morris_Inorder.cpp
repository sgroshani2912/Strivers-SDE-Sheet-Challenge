// https://rb.gy/d7nbh

#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    while(root != NULL){
        if(root->left == NULL){
            ans.push_back(root->data);
            root = root->right;
        }
        else{
            //Find rightmost node of left subtree
            TreeNode* pre = root->left;
            while(pre->right != NULL && pre->right!=root){
                pre = pre->right;
            }
            if(pre->right == NULL){
                pre->right = root;
                root = root->left;
            }
            else{
                pre->right = NULL;
                ans.push_back(root->data);
                root = root->right;
                
            }
        }
        
    }
    return ans;
}
