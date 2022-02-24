/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
   
    ListNode* merge(ListNode* l,ListNode* r)
    {
        ListNode* f=l;
        ListNode* s=r;
        ListNode* h=new ListNode(-1);
        ListNode* temp=h;
        while(f && s)
        {
            if(f->val <=s->val)
            {
                temp->next=f;
                f=f->next;
            }
            else
            {
                temp->next=s;
                s=s->next;
            }
            temp=temp->next;
            
        }
        if(f)
        {
            temp->next=f;
            f=f->next;
        }
        if(s)
        {
            temp->next=s;
            s=s->next;
        }
        return h->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head ->next == NULL)
            return head;
        ListNode *temp = NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        
        // 2 pointer appraoach / turtle-hare Algorithm (Finding the middle element)
        while(fast !=  NULL && fast -> next != NULL)
        {
            temp = slow;
            slow = slow->next;          //slow increment by 1
            fast = fast ->next ->next;  //fast incremented by 2
            
        }   
        temp -> next = NULL;            //end of first left half
        
        ListNode* l1 = sortList(head);    //left half recursive call
        ListNode* l2 = sortList(slow);    //right half recursive call
        
        return merge(l1, l2);    
    }
};