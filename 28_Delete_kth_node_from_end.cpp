//Problem link - https://shorturl.at/dpDMP
/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/
int len(Node* head){
    int cnt = 0;
    while(head!=NULL){
        cnt++;
        head=head->next;
    }
    return cnt;
}

Node* removeKthNode(Node* head, int K)
{
    int n = len(head);
    int cnt=0;
    Node* prev = NULL;
    Node* curr = head;

    while(cnt != n-K){
        prev = curr;
        curr = curr->next;
        
        cnt++;
    }
    if(prev==NULL){
        return head->next;
    }
    prev->next = curr->next;
    return head;

}
