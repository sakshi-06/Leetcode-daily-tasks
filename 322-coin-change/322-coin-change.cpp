class Solution {
public:
    int dp[13][10001];
    int solve(vector<int>&coins, int amount,int pos)
    {
        if(pos==coins.size()) return INT_MAX-1;
        if(amount==0) return 0;
        if(dp[pos][amount]!=-1) return dp[pos][amount];
        int ans=0;
        if(coins[pos]<=amount)
        {
            ans=min(1+solve(coins,amount-coins[pos],pos),solve(coins,amount,pos+1));
        }
        else ans=solve(coins,amount,pos+1);
        return dp[pos][amount]=ans;
        
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        if(solve(coins,amount,0)==INT_MAX-1) return -1;
        return solve(coins,amount,0);
            
    }
};