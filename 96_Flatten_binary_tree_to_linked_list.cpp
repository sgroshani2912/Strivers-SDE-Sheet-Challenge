// https://rb.gy/wakth

/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T dat)
        {
            this->data = dat;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void solve(TreeNode<int>* &root, TreeNode<int>* &prev){
    if(root == NULL){
        return ;
    }

    solve(root->right, prev);
    solve(root->left, prev);

    root->left = NULL;
    root->right = prev;
    prev = root;
}
void flattenBinaryTree(TreeNode<int>* root)
{
    TreeNode<int> * prev =NULL;
    solve(root, prev);

}
