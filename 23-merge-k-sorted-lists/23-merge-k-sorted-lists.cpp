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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> pq;
        for(int i=0;i<lists.size();i++)
        {
             if(lists[i])pq.push({lists[i]->val, lists[i]});
        }
        ListNode* curr=new ListNode(0);
        ListNode* head=curr;
        while(!pq.empty())
        {
            //int k=pq.top().first;
            ListNode* k=pq.top().second;
            head->next=new ListNode(pq.top().first);
            pq.pop();
            head=head->next;
            if(k->next) pq.push({k->next->val,k->next});
        }
        return curr->next;
    }
};