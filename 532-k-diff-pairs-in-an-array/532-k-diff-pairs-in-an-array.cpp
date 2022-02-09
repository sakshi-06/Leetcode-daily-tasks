class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        set<int> st(nums.begin(),nums.end());
        unordered_map<int,int> mp;
        for(auto &x:nums) mp[x]++;
        int cnt=0;
        for(auto &x:mp)
        {
            if(x.second>=2) cnt++;
        }
        if(k==0)
        {
            return cnt;
        }
        int ans=0;
        for(auto &x:st)
        {
            if(st.find(x-k)!=st.end())
            {
                ans++;
            }
        }
        return ans;
    }
};