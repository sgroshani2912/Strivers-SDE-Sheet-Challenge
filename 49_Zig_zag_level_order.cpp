// http://rb.gy/ny38l

#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> zigzagTreeTraversal(TreeNode<int> *root)
{
    vector<int> ans;
    if(root == NULL) return ans;
    queue<TreeNode<int>*> q;
    q.push(root);
    bool ltr = true;


    while(!q.empty()){
        int size = q.size();
        vector<int> temp(size);
        for(int i=0; i<size; i++){
            TreeNode<int>* node = q.front();
            q.pop();
            int idx = ltr? i : size-i-1;
            temp[idx] = node->data;

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);

        }
        ltr = !ltr;
        for(auto i:temp){
            ans.push_back(i);
        }
    } 
    return ans;
    
}
