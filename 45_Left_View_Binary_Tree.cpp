// https://rb.gy/olwam

//Using map
#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void solve(TreeNode<int>* root, map<int, vector<int>> &m, vector<int> &ans, int l){
    if(root==NULL) return;
    if(m[l].empty()) {
        ans.push_back(root->data);
        m[l].push_back(root->data);
    }
    solve(root->left, m, ans, l+1);
    solve(root->right, m, ans, l+1);
    return ;
}

vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> ans;
    //For horizontal distances and levels
    map<int, vector<int>> m;

    solve(root, m, ans, 0);
    return ans;
    

}


//Without using map
#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void solve(TreeNode<int> *root, int level, vector<int> &ans){
    if(root == NULL) return;
    if(ans.size()==level) ans.push_back(root->data);
    solve(root->left, level+1, ans);
    solve(root->right, level+1, ans);
    return;
}

vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> ans;
    int level = 0;
    solve(root, level, ans);
    return ans;
    
}
