// http://rb.gy/5ktg4

/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int solve(BinaryTreeNode<int> *root, int &sum){
    if(root == NULL){
        return 0;
    }

    int l = max(0,solve(root->left, sum));
    int r = max(0,solve(root->right, sum));

    sum = max(sum, root->data + l + r);
    return root->data + max(l,r);
    
}

int maxPathSum(BinaryTreeNode<int> *root)
{
    int sum = INT_MIN;
    int ans = solve(root, sum);
    return sum;

}
