//Problem link - https://shorturl.at/evPQ2

#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.

    if(first==NULL){
        return second;
    }
    if(second==NULL){
        return first;
    }
    
    Node<int>* head;
    if(first->data<=second->data){
        head = first;
        first = first->next;
    }
    else{
        head = second;
        second = second->next;
    }
    Node<int>* temp = head;
    while(first!=NULL && second!=NULL){
        
        if(first->data<=second->data){
            temp->next = first;
            temp = first;
            first=first->next;
        }
        else{
            temp->next = second;
            temp = second;
            second = second->next;
        }
    }
    while(first!=NULL){
        temp->next = first;
        temp = first;
        first=first->next;

    }
    while(second!=NULL){
        temp->next = second;
        temp = second;
        second = second->next;
    }
    return head;
}
