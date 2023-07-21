//Problem link - https://shorturl.at/cnAQ3

//Using hashset, TC = O(max(M,N)), SC = O(M)
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
#include <bits/stdc++.h>

Node* findIntersection(Node *firstHead, Node *secondHead)
{
    unordered_set<Node*> s;
    while(firstHead){
        s.insert(firstHead);
        firstHead = firstHead->next;
    }
    while(secondHead){
        if(s.find(secondHead)!=s.end()){
            return secondHead;
        }
        secondHead = secondHead->next;
    }
    return NULL;
}
