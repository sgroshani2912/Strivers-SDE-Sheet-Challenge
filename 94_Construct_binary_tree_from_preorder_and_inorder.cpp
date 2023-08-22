// https://rb.gy/sqwzu

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
//idx id to travel preorder
//start and end are for inorder 
TreeNode<int> *build(vector<int> &inorder, vector<int> &preorder, int &idx, int start, int end ){
    if(idx>=preorder.size() || start>end){
        return NULL;
    }
    int curr = preorder[idx++];
    TreeNode<int> * temp = new TreeNode<int> (curr);
    int find;
    for(int i = start; i<=end; i++){
        if(inorder[i]==curr){
            find = i;
            break;
        }
    }
    temp->left = build(inorder, preorder, idx, start, find-1);
    temp->right = build(inorder, preorder, idx, find+1, end);
    return temp;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{   
    int idx = 0;
    TreeNode<int> *ans = build(inorder, preorder, idx, 0, preorder.size()-1);
    return ans;
	
}
