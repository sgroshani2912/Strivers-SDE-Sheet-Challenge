//https://rb.gy/5ha1y
#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int getMaxWidth(TreeNode<int> *root)
{
    int ans = 0;
    if(root == NULL) return ans;
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        ans = max(ans, size);
        for(int i=0; i<size; i++){
            auto node = q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
    return ans;
    
}
