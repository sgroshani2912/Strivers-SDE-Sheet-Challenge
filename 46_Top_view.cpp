// http://rb.gy/ksczq

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

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

vector<int> getTopView(TreeNode<int> *root) {
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    map<int, int> m;
    queue<pair<TreeNode<int>*, int>> q;
    q.push({root, 0});

    while(!q.empty()){
        auto front = q.front();
        q.pop();
        TreeNode<int>* node = front.first;
        int x = front.second;
        if(m.find(x) == m.end()){
            m[x] = node->val;
        }
        
        if(node->left){
            q.push({node->left, x-1});
        }
        if(node->right){
            q.push({node->right, x+1});
        }

    }
    for(auto i:m){
        ans.push_back(i.second);
    }
    return ans;
}
