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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k==0 || !head->next)
        {
            return head;
        }
        int len=0;
        ListNode* curr=head;
        while(curr)
        {
            curr=curr->next;
            len++;
        }
        k=k%len;
        if(k==0) return head;
        int p=len-k;
        p--;
        ListNode* temp=head;
        ListNode* end=head;
        ListNode* ans=head;
        while(end->next)
        {
            end=end->next;
        }
        while(p--)
        {
            temp=temp->next;
        }
        ans=temp->next;
        temp->next=nullptr;
        
        end->next=head;
        return ans;
        
    }
};