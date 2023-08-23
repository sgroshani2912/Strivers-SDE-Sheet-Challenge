// https://rb.gy/o7vo8

/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*************************************************************/
TreeNode* help(vector<int> &pre,int &i,int bound){
    if(i>=pre.size() || pre[i]>=bound)return NULL;
    TreeNode* root=new TreeNode(pre[i++]);
    root->left=help(pre,i,root->data);
    root->right=help(pre,i,bound);
    return root;
}
TreeNode* preOrderTree(vector<int> &pre){
    // Write your code here.
    int i=0;
    return help(pre,i,INT_MAX);
}
