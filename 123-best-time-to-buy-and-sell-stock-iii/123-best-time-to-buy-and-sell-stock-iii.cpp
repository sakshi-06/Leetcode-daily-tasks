class Solution {
public:
    int dp[100001][3][2];
    int solve(int idx,vector<int>& prices,int k,int stock)
    {
        if(idx>=prices.size()) return 0;
        if(k<=0) return 0;
        if(dp[idx][k][stock]!=-1) return dp[idx][k][stock];
        int ans=0;
        if(stock)
        {
            ans=max(solve(idx+1,prices,k-1,0)+prices[idx],solve(idx+1,prices,k,1));
        }
        else
        {
            ans=max(solve(idx+1,prices,k,1)-prices[idx],solve(idx+1,prices,k,0));
        }
        return dp[idx][k][stock]=ans;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp, -1,sizeof(dp));
        return solve(0,prices,2,0);
    }
};