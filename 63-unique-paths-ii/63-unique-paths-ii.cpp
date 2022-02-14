class Solution {
public:
    int dp[101][101];
    int solve(int i,int j,vector<vector<int>> &grid)
    {
        
        if(i>=grid.size() || j>=grid[0].size()) return 0;
        if(grid[i][j]==1) return 0;
        if(i==grid.size()-1 && j==grid[0].size()-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        ans=solve(i+1,j,grid)+solve(i,j+1,grid);
        return dp[i][j]=ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp, -1, sizeof(dp));
        return solve(0,0,obstacleGrid);
    }
};