// https://rb.gy/fnjql

/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
*/

pair<bool, int> isPossible(Node *root){
    if(root==NULL){
        return make_pair(true, 0);
    }
    if(root->left == NULL && root->right == NULL){
        return make_pair(true, root->data);
    }
    pair<bool, int> l = isPossible(root->left);
    pair<bool, int> r = isPossible(root->right);

    if(l.first && r.first){
        if(root->data == l.second+r.second){
            return make_pair(true, root->data);
        }
    }
    return make_pair(false, root->data);
}

bool isParentSum(Node *root){
    pair<bool, int> ans = isPossible(root);
    return ans.first;
}
