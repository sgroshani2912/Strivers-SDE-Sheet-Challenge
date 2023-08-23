// http://rb.gy/uqv86

#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
//Approach 2 - using max and min concept
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    BinaryTreeNode<int>* temp = root;
    int pre = -1;
    int succ = -1;
    while(temp->data != key){
        if(temp->data > key){
            succ = temp->data;
            temp = temp->left;
            
        }
        else{
            pre = temp->data;
            temp = temp->right;
            
        }
    }

    BinaryTreeNode<int>* pre_ans = temp->left;
    while(pre_ans != NULL){
        pre = pre_ans->data;
        pre_ans = pre_ans->right;
        
    }
    BinaryTreeNode<int>* succ_ans = temp->right;
    while(succ_ans != NULL){
        succ = succ_ans->data;
        succ_ans = succ_ans->left;
    }
    
    pair<int,int> ans = make_pair(pre,succ);
    return ans;
    
}
