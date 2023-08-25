// https://rb.gy/ele99

/**********************************************************
    Following is the Binary Tree Node structure:

    class BinaryTreeNode
    {
    public:
        int data;
        BinaryTreeNode *left, *right;
        BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
        BinaryTreeNode(int x) : data(x), left(NULL), right(NULL) {}
        BinaryTreeNode(int x, BinaryTreeNode *left, BinaryTreeNode *right) : data(x), left(left), right(right) {}
    };
***********************************************************/
void solve(BinaryTreeNode *root, vector<int> &in){
    if(root == NULL){
        return ;
    }
    solve(root->left, in);
    in.push_back(root->data);
    solve(root->right, in);
}
bool pairSumBst(BinaryTreeNode *root, int k)
{
    vector<int> in;
    solve(root, in);
    int s = 0;
    int e = in.size()-1;
    while(s<e){
        if(in[s]+in[e] == k){
            return true;
        }
        else if(in[s] + in[e] < k){
            s++;
        }
        else{
            e--;
        }

    }
    return false;
}
