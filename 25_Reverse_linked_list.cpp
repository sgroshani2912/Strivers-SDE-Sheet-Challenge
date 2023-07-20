//Problem link - https://shorturl.at/egxB5


//Recursive approach, TC=O(N), SC = O(N)
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
void solve(LinkedListNode<int> * &head,LinkedListNode<int> *curr, LinkedListNode<int> *prev){

    if(curr==NULL){
        head = prev;
        return;
    }
    LinkedListNode<int> *temp = curr->next;
    solve(head,curr->next,curr);
    curr->next=prev;
    
}
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    LinkedListNode<int> * curr = head;
    LinkedListNode<int> * prev = NULL;
    solve(head,curr,prev);
    return head;
    
}

//Iterative approach, TC=O(N), SC = O(1)
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

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    if(head == NULL || head->next == NULL){
        return head;
    }

    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *curr = head;
    LinkedListNode<int> *nex = NULL;
    
    while(curr != NULL ){
        nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
        
    }

    return prev;
    
}
