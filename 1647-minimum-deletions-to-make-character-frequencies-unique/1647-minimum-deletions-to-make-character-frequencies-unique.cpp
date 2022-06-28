class Solution {
public:
    int minDeletions(string s) {
      priority_queue<int> pq;
        unordered_map<char,int> mp;
        for(auto &ch:s)
        {
            mp[ch]++;
        }
        for(auto x:mp)
        {
            pq.push(x.second);
        }
        int ans=0;
        while(pq.size()>1)
        {
            int t=pq.top();
            pq.pop();
            if(t==pq.top())
            {
                if(t-1>0)
                {
                    pq.push(t-1);
                }
                ans++;
            }
        }
        return ans;
    }
};