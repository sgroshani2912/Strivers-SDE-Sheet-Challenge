//Problem link - http://rb.gy/3z2mi

#include <bits/stdc++.h>
/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *random;
 *		Node() : data(0), next(nullptr), random(nullptr){};
 *		Node(int x) : data(x), next(nullptr), random(nullptr) {}
 *		Node(int x, Node *next, Node *random) : data(x), next(next), random(random) {}
 * };
 */

//Solution using map, TC = O(N), SC = O(N)
Node *cloneLL(Node *head){
	unordered_map<Node*, Node*> m;
	Node* cloneHead = new Node(-1);
	Node* temp2 = cloneHead;
	Node* temp1 = head;
	while(temp1 != NULL){
		Node* cloneNode = new Node(temp1->data);
		temp2->next = cloneNode;
		temp2 = temp2->next;
		m[temp2] = temp1;
		temp1 = temp1->next;
	}

	temp2 = cloneHead->next;
	while(temp2 != NULL){
		temp2->random = m[temp2]->random;
		temp2 = temp2->next;
	}

	return cloneHead->next;
}
