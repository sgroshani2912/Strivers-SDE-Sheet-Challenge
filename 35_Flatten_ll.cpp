//Problem link - http://rb.gy/wrcpr

#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

*****************************************************************/
Node* merge(Node* down, Node*across){
    Node* first = down;
    Node* second = across;
	Node* head = new Node(-1);
    Node* result = head;
    

	if(!first){
		return second;
	}
	if(!second){
		return first;
	}
   
    while(first && second){
        if(first->data<second->data){
            result->child=first;
            result = result->child;
            first = first->child;

        }
        else{
            result->child = second;
            result = result->child;
            second = second->child;
        }
    }
    if(first){
        result->child=first;
        result = result->child;
        first = first->child;

    }
    else{
        result->child = second;
        result = result->child;
        second = second->child;
    }
    return head->child;
}


Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	if(head==NULL || head->next==NULL){
		return head;
	}

	Node* down = head;
	Node* across = head->next;
	head->next = NULL;


	across = flattenLinkedList(across);

	Node* ans = merge(down,across);

	return ans;
}
