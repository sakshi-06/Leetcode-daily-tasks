class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0;
        int j=0,ans=0;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum==k) ans++;
            if(mp.find(sum-k)!=mp.end())
            {
                ans+=mp[sum-k];
            }
            mp[sum]++;
        }
        return ans;
    }
};