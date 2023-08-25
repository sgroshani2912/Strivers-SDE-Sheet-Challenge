// https://rb.gy/nzg8v

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(T x) : data(x), left(NULL), right(NULL) {}
        TreeNode(T x, TreeNode<T> *left, TreeNode<T> *right) : data(x), left(left), right(right) {}
    };

************************************************************/
void inorder(TreeNode<int> *root, int &res, int &k){
    if(root==NULL){
        return;
    }
    inorder(root->left, res, k);
    k--;
    if(k==0){
        res = root->data;
    }
    inorder(root->right, res ,k);
}
int kthSmallest(TreeNode<int> *root, int k)
{
    int res= 0;
    inorder(root, res, k);
    return res;
}
