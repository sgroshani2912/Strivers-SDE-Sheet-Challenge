//Problem link - https://shorturl.at/lqwzB

//Using slow and fast pointer, TC = O(N), SC=O(1)
/****************************************************************

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


*****************************************************************/

bool detectCycle(Node *head)
{
	if(head == NULL || head->next==NULL){
        return false;
    }

    Node* slow = head;
    Node* fast = head->next;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
        }
        if(slow==NULL || fast == NULL){
            return false;
        }
    }
    return true;
}
