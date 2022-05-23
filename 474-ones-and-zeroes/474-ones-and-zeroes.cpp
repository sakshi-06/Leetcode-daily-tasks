class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        for(auto &s:strs)
        {
            int ones=0,zeros=0;
            for(auto &x:s)
            {
                if(x=='0') zeros++;
                else ones++;
            }
            for(int i=m;i>=zeros;i--)
            {
                for(int j=n;j>=ones;j--)
                {
                    dp[i][j]=max(dp[i][j],1+dp[i-zeros][j-ones]);
                }
            }
        }
        return dp[m][n];

        }
};