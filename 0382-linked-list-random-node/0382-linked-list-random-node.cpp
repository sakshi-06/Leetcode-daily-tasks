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
    ListNode* root;
    Solution(ListNode* head) {
        root=head;
    }
    
    int getRandom() {
        int i=1;
        ListNode* curr=root;
        ListNode* ans=nullptr;
        while(curr)
        {
            if(rand()%i==0)
            {
                ans=curr;
            }
            i++;
            curr=curr->next;
        }
        return ans->val;
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */