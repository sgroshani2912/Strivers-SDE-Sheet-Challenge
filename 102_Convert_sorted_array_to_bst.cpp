// https://rb.gy/vipb4

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
TreeNode<int>* construct(vector<int> &arr, int start,int end){
    if(start > end){
        return NULL;
    }
    int mid = start + (end-start)/2;
    TreeNode<int> * temp = new TreeNode<int>(arr[mid]);
    temp->left = construct(arr, start, mid-1);
    temp->right = construct(arr, mid+1, end);
    return temp;
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    return construct(arr, 0, n-1);

}
