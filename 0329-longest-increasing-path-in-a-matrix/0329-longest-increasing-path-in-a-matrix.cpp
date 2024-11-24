class Solution {
public:
    int solve(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j, int prev){
        if(i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size() || prev>=matrix[i][j]){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        dp[i][j]=0;
        dp[i][j]=1+max({solve(matrix, dp, i+1, j, matrix[i][j]),
                        solve(matrix, dp, i-1, j, matrix[i][j]),
                       solve(matrix, dp, i, j+1, matrix[i][j]),
                       solve(matrix, dp, i, j-1, matrix[i][j])});
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans =0;
        vector<vector<int>> dp(n, vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans, solve(matrix, dp, i, j, -1));
            }
        }
        return ans;
    }
};