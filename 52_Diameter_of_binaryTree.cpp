// http://rb.gy/ein62

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
pair<int, int> solve(TreeNode<int>* root){
    if(root == NULL){
        return {0,0};
    }

    auto left_ans = solve(root->left);
    auto right_ans = solve(root->right);

    int both = left_ans.second + right_ans.second;
    int dia = max(1+both, max(left_ans.first, right_ans.first));
    int hgt = 1+max(left_ans.second, right_ans.second);

    return {dia, hgt};
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    pair<int, int> ans = solve(root);
    return ans.first - 1;
	
}
