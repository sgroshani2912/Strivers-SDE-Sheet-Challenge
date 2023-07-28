// http://rb.gy/thn30

//Recursive Approach
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

void solve(TreeNode *root, vector<int> &ans){
    if(root == NULL) return ;
    solve(root->left, ans);
    ans.push_back(root->data);
    solve(root->right, ans);
    return;
}
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    solve(root, ans);
    return ans;
}

//Iterative Approach
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
    stack<TreeNode*> s;
    while(!s.empty() || root!=NULL){
        while(root!=NULL){
            s.push(root);
            root = root->left;
        }
        root = s.top();
        ans.push_back(root->data);
        s.pop();
        root = root->right;
    }
    return ans;
}
