class Solution {
public:
    int dp[1001][1001];
    int solve(int i,int j,string &t1,string &t2)
    {
        if(i==0 || j==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(t1[i-1]==t2[j-1])
        {
            ans=1+solve(i-1,j-1,t1,t2);
        }
        else
        {
            ans=max(solve(i-1,j,t1,t2), solve(i, j-1, t1, t2));
        }
        return dp[i][j]=ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        memset(dp, -1, sizeof(dp));
        return solve(n ,m ,text1, text2);
        
    }
};