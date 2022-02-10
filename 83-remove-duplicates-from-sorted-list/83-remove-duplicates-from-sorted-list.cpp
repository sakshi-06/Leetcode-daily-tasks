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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return nullptr;
        int pre=head->val;
        ListNode* t=head;
        ListNode* p=head->next;
        while(p)
        {
            if(pre!=p->val)
            {
                t->next=p;
                pre=p->val;
                t=t->next;
            }
            p=p->next;
        }
        t->next=nullptr;
        return head;
    }
};