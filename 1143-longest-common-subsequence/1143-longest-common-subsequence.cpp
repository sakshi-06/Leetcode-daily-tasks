class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        dp[0][0]=0;
        for(int i=0;i<=text2.size();i++)
        {
            dp[0][i]=0;
        }
        for(int i=0;i<=text1.size();i++)
        {
            dp[i][0]=0;
        }
        for(int i=1;i<=text1.size();i++)
        {
            for(int j=1;j<=text2.size();j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max({dp[i-1][j],dp[i][j-1]});
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
};