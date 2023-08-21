// https://rb.gy/i32v1

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode
    {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val)
        {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
pair<bool,int> solve(TreeNode<int>* root){
    if(root == NULL){
        return make_pair(true,0);
    }
    pair<bool, int> left = solve(root->left);
    pair<bool, int> right = solve(root->right);

    pair<bool, int> ans;
    if(left.first == true && right.first == true && abs(left.second - right.second)<=1){
        ans.first = true;
        
    }
    else{
        ans.first = false;
    }
    ans.second = 1 + max(left.second, right.second);
    return ans;

}
bool isBalancedBT(TreeNode<int>* root){
    pair<bool, int> ans =  solve(root);
    return ans.first;

}
