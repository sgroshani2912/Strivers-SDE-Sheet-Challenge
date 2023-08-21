// https://rb.gy/rjx7e

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

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	if(root==NULL){
        return -1;
    }
    if(root->data == x || root->data == y){
        return root->data;
    }
    int left_ans  = lowestCommonAncestor(root->left, x, y);
    int right_ans = lowestCommonAncestor(root->right, x, y);

    if(left_ans == -1){
        return right_ans;
    }
    else if(right_ans == -1){
        return left_ans;
    }
    else if(left_ans != -1 && right_ans != -1){
        return root->data;
    }

}
