//Problem link - https://rb.gy/ac80i

//TC = O(N), SC=O(1)
#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverse(LinkedListNode<int> *head){
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *curr = head;
    LinkedListNode<int> *forw;
    while(curr){
        forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
    }
    return prev;
}

bool isPalindrome(LinkedListNode<int> *head) {
    if(head==NULL || head->next==NULL){
        return true;
    }
    LinkedListNode<int> *slow = head;

    LinkedListNode<int> *fast = head;

    while(fast->next!=NULL && fast->next->next!=NULL){

        slow = slow->next;

        fast = fast->next->next;

    }

    LinkedListNode<int> *head2 = slow->next;

    slow->next = NULL;

    head2 = reverse(head2);

    while(head2!=NULL){

        if(head->data!=head2->data) return false;

        head = head->next;

        head2 = head2->next;

    }

    return true;
    

}
