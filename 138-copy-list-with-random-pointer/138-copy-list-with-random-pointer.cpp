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
        Node* temp=head;
        while(temp)
        {
            Node* n=new Node(temp->val);
            n->next=temp->next;
            temp->next=n;
            temp=n->next;
        }
        temp=head;
        while(temp && temp->next)
        {
            if(temp->random) temp->next->random=temp->random->next;
            temp=temp->next->next;
        }
        temp=head;
        Node* h1=NULL;
        Node* t1=NULL;
        while(temp && temp->next)
        {
            if(!h1)
            {
                h1=temp->next;
                t1=temp->next;
            }
            else
            {
                t1->next=temp->next;
                t1=t1->next;
            }
            temp->next=temp->next->next;
            temp=temp->next;
        }
        return h1;
    }
};