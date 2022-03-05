class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());
        vector<int>cn(mx+1,0);
        for(auto x:nums)cn[x]++;
        vector<int>dp(mx+1);
        dp[0]=0;
        dp[1]=cn[1];
        for(int i=2;i<mx+1;i++)dp[i]=max(dp[i-1],dp[i-2]+cn[i]*i);
        return dp[mx];
    }
};