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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string s;
        int carry=0;
        while(l1 && l2)
        {
            int x=l1->val;
            int y=l2->val;
            s+=to_string((x+y+carry)%10);
            carry= (x+y+carry)/10;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1)
        {
            s+=to_string((l1->val+carry)%10);
            carry= (l1->val+carry)/10;
            l1=l1->next;
        }
        while(l2)
        {
            s+=to_string((l2->val+carry)%10);
            carry= (l2->val+carry)/10;
            l2=l2->next;
        }
        if(carry!=0) s+=to_string(carry);
        //reverse(s.begin(), s.end());
        ListNode *dummy= new ListNode(0);
        ListNode *head=dummy;
        for(int i=0;i<s.size();i++)
        {
            ListNode *n = new ListNode(s[i]-'0');
            head->next=n;
            head=head->next;
        }
        return dummy->next;
    }
};