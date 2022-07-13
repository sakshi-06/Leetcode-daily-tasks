class Solution {
public:
    int dp[1001][51];
    int solve(int i, vector<int> &nums,int n,int m)
    {
        if(i==n && m==0) return 0;
        if(i==n||m==0) return INT_MAX;
        if(dp[i][m]!=-1) return dp[i][m];
        int ans=INT_MAX;
        for(int ind=i;ind<n;ind++)
        {
            int sum=nums[ind]-((i-1>=0)?nums[i-1]:0);
            int ff=solve(ind+1,nums,n,m-1);
            ans=min(ans,max(sum,ff));
        }
        return dp[i][m]=ans;
    }
    int splitArray(vector<int>& nums, int m) {
        memset(dp, -1, sizeof(dp));
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==INT_MAX) return INT_MAX;
            nums[i]+=((i-1>=0)?nums[i-1]:0);
        }
        return solve(0,nums,n,m);
    }
};