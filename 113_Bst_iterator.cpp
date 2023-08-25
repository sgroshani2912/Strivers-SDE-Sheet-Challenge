// https://rb.gy/3sif9

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

class BSTiterator
{   
    queue<int> q;
    void inorder(TreeNode<int> *root){
        if(root == NULL){
            return;
        }
        inorder(root->left);
        this->q.push(root->data);
        inorder(root->right);
    }
    public:
    BSTiterator(TreeNode<int> *root)
    {
        inorder(root);
    }

    int next()
    {
        if(q.empty()){
            return -1;
        }
        else{
            int ans = q.front();
            q.pop();
            return ans;
        }
    }

    bool hasNext()
    {
        if(q.empty()){
            return false;
        }
        return true;
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/
