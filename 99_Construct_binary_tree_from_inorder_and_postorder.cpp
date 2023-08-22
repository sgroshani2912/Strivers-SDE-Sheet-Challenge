// https://rb.gy/wah3m

/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
TreeNode<int> *build(vector<int> &inOrder, vector<int> &postOrder, int &idx, int start, int end ){
    if(idx<0 || start>end){
        return NULL;
    }
    int curr = postOrder[idx--];
    TreeNode<int> * temp = new TreeNode<int> (curr);
    int find;
    for(int i = start; i<=end; i++){
        if(inOrder[i]==curr){
            find = i;
            break;
        }
    }
    
    temp->right = build(inOrder, postOrder, idx, find+1, end);
    temp->left = build(inOrder, postOrder, idx, start, find-1);
    return temp;
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder){
    int idx = postOrder.size()-1;
    TreeNode<int> *ans = build(inOrder, postOrder, idx, 0, postOrder.size()-1);
    return ans;
	
}
