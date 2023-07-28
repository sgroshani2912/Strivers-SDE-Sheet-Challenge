//http://rb.gy/cpn7h

#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> bottomView(BinaryTreeNode<int> * root){

    vector<int> ans;
    map<int, int> m;
    queue<pair<BinaryTreeNode<int>*, int>> q;
    pair<BinaryTreeNode<int>*, int> temp = make_pair(root, 0);
    q.push(temp);

    

    while(!q.empty()){
        auto front = q.front();
        q.pop();
        m[front.second] = front.first->data;
        if(front.first->left){
            q.push(make_pair(front.first->left, front.second -1));
        }
        if(front.first->right){
            q.push(make_pair(front.first->right, front.second +1));
        }

    }
    for(auto i:m){
        ans.push_back(i.second);
    }
    return ans;
}
