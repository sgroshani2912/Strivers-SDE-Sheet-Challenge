// https://rb.gy/kf4tq

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
bool solve(TreeNode<int> *root1, TreeNode<int> *root2){
    if(root1 == NULL || root2 == NULL){
        return root1==root2;
    }
    return (root1->data == root2->data) && (solve(root1->left, root2->right) && solve(root1->right, root2->left));
}
bool isSymmetric(TreeNode<int> *root)
{
    if(root == NULL){
        return true;
    }

    return solve(root->left, root->right);
}
