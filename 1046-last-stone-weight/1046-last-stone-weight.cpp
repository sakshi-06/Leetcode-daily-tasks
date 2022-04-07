class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(),stones.end());
        while(pq.size()>1)
        {
            int k=pq.top();
            pq.pop();
            int l=pq.top();
            pq.pop();
            if(l==k)
            {
                continue;
            }
            else
            {
                pq.push(abs(k-l));
            }
        }
        if(pq.size()==0) return 0;
        return pq.top();
        
    }
};