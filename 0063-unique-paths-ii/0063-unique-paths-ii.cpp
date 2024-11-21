class Solution {
public:
    int dp[101][101];
    int solve(vector<vector<int>>& obstacleGrid, int x, int y, int n, int m)
    {
        if(x>n-1 || y>m-1 || obstacleGrid[x][y]==1) return 0;
        if(x==n-1 && y==m-1)
            return 1;
        if(obstacleGrid[x][y] == 1) return dp[x][y]=0;
        if(dp[x][y]!=-1) return dp[x][y];
        return dp[x][y] = solve(obstacleGrid, x+1, y, n, m) + solve(obstacleGrid, x, y+1, n,m);
    }
    
       
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp, -1, sizeof(dp));
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        return solve(obstacleGrid, 0, 0,n,m);
    } 
};