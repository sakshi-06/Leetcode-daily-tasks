class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
       int n=grid.size();
        int m =grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1) return 0;
        vector<vector<int>> dp(n,vector<int>(m,0));
        dp[0][0]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    dp[i][j]=0;
                    continue;
                }
                else if(i==0 && j==0) dp[i][j]=1;
                else if(i==0)
                {
                    dp[i][j]=dp[i][j-1];
                }
                else if(j==0)
                {
                    dp[i][j]=dp[i-1][j];
                }
                else
                {
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[n-1][m-1];
    }
};