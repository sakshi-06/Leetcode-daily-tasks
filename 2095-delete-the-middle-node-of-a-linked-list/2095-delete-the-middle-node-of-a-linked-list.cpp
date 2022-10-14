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
    int find_len(ListNode* head)
    {
        int len=0;
        while(head!=nullptr)
        {
            head=head->next;
            len++;
        }
        return len;
    }
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || head->next==nullptr) return nullptr;
        int len=find_len(head);
        int mid=len/2;
        mid--;
        ListNode* temp=head;
        while(mid--)
        {
            temp=temp->next;
        }
        temp->next=temp->next->next;
        //delete(temp);
        return head;
    }
};