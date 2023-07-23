//Problem link - http://rb.gy/sgrws

/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

//Function to find the length of the linked list
int length(Node *head){
     int cnt = 0;
     while(head!=NULL){
          cnt++;
          head = head->next;
     }
     return cnt;
}

Node *rotate(Node *head, int k) {
     if(head==NULL || head->next == NULL){
          return head;
     }
     Node* curr = head;
     int n = length(head);
     k = n-(k%n);
     while(curr->next!=NULL){
          curr = curr->next;
     }
     curr->next = head;
     while(k--){
          curr = curr->next;
     }
     head = curr->next;
     curr->next = NULL;
     return head;




}
