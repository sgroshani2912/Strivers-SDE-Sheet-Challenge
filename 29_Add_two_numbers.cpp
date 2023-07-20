//Problem link - https://shorturl.at/mqryY

/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *num1, Node *num2)
{
    
    int c = 0;
    Node* head = new Node(-1);
    Node* ptr = head;
    while(num1 && num2){
        int d = (num1->data + num2->data + c)%10;
        c = (num1->data + num2->data + c)/10;
        Node* temp = new Node(d);
        ptr->next = temp;
        ptr = temp;
        num1 = num1->next;
        num2 = num2->next;
    }
    while(num1){
        int d = (num1->data + c)%10;
        c = (num1->data + c)/10;
        Node* temp = new Node(d);
        ptr->next = temp;
        ptr = ptr->next;
        num1 = num1->next;
        
    }
    while(num2){
        int d = (num2->data + c)%10;
        c = (num2->data + c)/10;
        Node* temp = new Node(d);
        ptr->next = temp;
        ptr = ptr->next;
        num2 = num2->next;
    }
    if(c!=0){
        Node* temp = new Node(c);
        ptr->next = temp;
        ptr = ptr->next;
    }
    return head->next;

}
