class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[coins.size()+1][amount+1];
        for(int i=0;i<=coins.size();i++)
        {
            dp[i][0]=0;
        }
        for(int i=0;i<=amount;i++)
        {
            dp[0][i]=INT_MAX/2;
        }
        dp[0][0]=0;
        for(int i=1;i<=coins.size();i++)
        {
            for(int j=1;j<=amount;j++)
            {
                if(j-coins[i-1]>=0)
                {
                    dp[i][j]=min(1+dp[i][j-coins[i-1]], dp[i-1][j]);
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        if(dp[coins.size()][amount]==INT_MAX/2) return -1;
        return dp[coins.size()][amount];
    }
};