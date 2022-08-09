/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *iter = head;
        Node *front = head;
        //step 1 : making deepcopy and handling next pointers;    
        while(iter!=NULL)
        {
                front = iter->next;
                Node *n = new Node(iter->val);
                iter->next=n;
                n->next=front;
                iter=front;
        }
        //step 2 : marking random pointer of deep copy    
        iter = head;
        while(iter!=NULL)
        {
                if(iter->random!=NULL)
                iter->next->random = iter->random->next;
                iter = iter->next->next;
        }
        Node *pseudo = new Node(0);
        Node *copy = pseudo;
        iter = head;
        while(iter!=NULL)
        {
                front = iter->next->next;
                copy->next = iter->next;
                iter->next=front;
                iter=iter->next;
                copy=copy->next;
        }
            
        return pseudo->next;
    }
};
