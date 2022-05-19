class Solution {
public:
    int solve(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j, int prev)
    {
        if(i<0 || i>=matrix.size()|| j<0 || j>=matrix[0].size()|| matrix[i][j]<=prev)
            return 0;
        if(dp[i][j]!=0) return dp[i][j];
        int path1=solve(matrix, dp, i+1, j, matrix[i][j]);
        int path2=solve(matrix, dp, i-1, j, matrix[i][j]);
        int path3=solve(matrix, dp, i, j+1, matrix[i][j]);
        int path4=solve(matrix, dp, i, j-1, matrix[i][j]);
        dp[i][j]= 1+ max(max(max(path1, path2),path3),path4);
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int max_len=-1;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(),0));
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(dp[i][j]==0)
                {
                    solve(matrix, dp,i, j, INT_MIN);
                    max_len = max(max_len ,dp[i][j]);
                }
            }
        }
        return max_len;
    }
};