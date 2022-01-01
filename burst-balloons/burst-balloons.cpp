class Solution {
public:
    int dp[501][501];
    int solve(vector<int> &nums,int i,int j)
    {
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MIN;
        for(int k=i;k<=j;k++)
        {
            int curr=nums[i-1]*nums[k]*nums[j+1]+solve(nums,i,k-1)+solve(nums,k+1,j);
            ans=max(ans,curr);
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        memset(dp, -1, sizeof(dp));
        return solve(nums,1,nums.size()-2);
    }
};