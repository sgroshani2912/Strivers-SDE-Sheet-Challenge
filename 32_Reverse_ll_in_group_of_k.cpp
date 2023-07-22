//Problem link - https://rb.gy/v6lm7

//TC = O(N), SC = O(1)
#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
Node* reverse(Node* &tail, Node* &start, int k){
	if(k==0) return NULL;
	Node* prev = NULL;
	Node* curr = tail;
	Node* forw;
	while(curr && k--){
		forw = curr->next;
		curr->next = prev;
		prev = curr;
		curr = forw;
	}
	start = tail;
	tail = curr;
	return prev;
}

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	if(head==NULL || head->next == NULL){
		return head;
	}

	Node* dummy = new Node(-1);
	Node* start = dummy;
	Node* tail = head;
	int i=0;
	while(i<n && tail!=NULL){
		start->next = reverse(tail, start, b[i]);
		i++;
	}
	if(tail!=NULL){
		start->next = tail;
	}
	return dummy->next;
}
