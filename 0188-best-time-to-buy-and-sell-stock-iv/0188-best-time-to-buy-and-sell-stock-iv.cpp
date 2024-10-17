class Solution {
public:
    int dp[100001][101][2];
    int solve(vector<int> &prices, int k, int stock,int idx){
        if(idx>=prices.size()) return 0;
        if(k<=0)return 0;
        if(dp[idx][k][stock]!=-1) return dp[idx][k][stock];
        int ans=0;
        if(stock)
        {
            ans=max(solve(prices,k-1,0,idx+1)+prices[idx],solve(prices,k,1,idx+1));
        }
        else
        {
            ans=max(solve(prices,k,1, idx+1)-prices[idx],solve(prices,k,0, idx+1));
        }
        return dp[idx][k][stock]=ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1,sizeof(dp));
        return solve(prices,k,0,0);
    }
};