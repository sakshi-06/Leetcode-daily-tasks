class Solution {
public:
    int dp[101][101];
    int solve(vector<vector<int>> &matrix,int i, int j)
    {
        if(i>=matrix.size()) return 0;
        if(j<0 || j>=matrix[0].size()) return INT_MAX;
        if(dp[i][j]) return dp[i][j];
        return dp[i][j]=matrix[i][j]+min({solve(matrix, i+1,j-1),solve(matrix,i+1, j), solve(matrix, i+1, j+1)});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
       // solve(matrix, 0, 0);
        int ans=INT_MAX;
        for(int j=0;j<matrix[0].size();j++){
            ans=min(ans,solve(matrix,0,j));
        }
        
        return ans;
    }
};