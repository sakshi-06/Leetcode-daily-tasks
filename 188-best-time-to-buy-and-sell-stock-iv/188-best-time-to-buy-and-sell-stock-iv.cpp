class Solution {
public:
    int dp[10001][101][2];
    int solve(int idx,int stock,vector<int> prices,int k)
    {
        if(idx>=prices.size()) return 0;
        if(k<=0) return 0;
        if(dp[idx][k][stock]!=-1) return dp[idx][k][stock];
        int ans=0;
        if(stock)
        {
            ans=max(prices[idx]+solve(idx+1,0,prices,k-1),solve(idx+1,1,prices,k));
        }
        else
        {
            ans=max(-prices[idx]+solve(idx+1,1,prices,k),solve(idx+1,0,prices,k));
        }
        return dp[idx][k][stock]=ans;
        
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1,sizeof(dp));
        return solve(0,0,prices,k);
    }
};