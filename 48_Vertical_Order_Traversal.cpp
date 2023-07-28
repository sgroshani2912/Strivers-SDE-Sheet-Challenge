// http://rb.gy/5qqql

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

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<int> ans;
    map<int, map<int, vector<int>>> m;
    queue<pair<TreeNode<int> *,pair<int, int>>> q;
    q.push({root, {0,0}});

    while(!q.empty()){
        auto front = q.front();
        q.pop();
        TreeNode<int>* node = front.first;
        int x = front.second.first;
        int y = front.second.second;
        m[x][y].push_back(node->data);

        if(node->left){
            q.push({node->left, {x-1, y+1}});
        }
        if(node->right){
            q.push({node->right, {x+1, y+1}});
        }
    } 

    for(auto i : m){
        for(auto j : i.second){
            for(int k: j.second){
                ans.push_back(k);
            }
            
        }
    }
    return ans;
    
}
