class Solution {
public:
    int dp[201][201];
    int solve(vector<vector<int>> &grid,int x, int y)
    {
      if(dp[x][y]!=-1) return dp[x][y];
        if(x==0 && y==0) return grid[x][y];
        if(x == 0) return dp[x][y]=grid[x][y] + solve(grid,x,y-1);
        if(y == 0) return dp[x][y]=grid[x][y] + solve(grid,x-1,y);
        return dp[x][y]= grid[x][y] + min (solve(grid, x-1,y) , solve(grid,x,y-1) );  
    }
    int minPathSum(vector<vector<int>>& grid) {
        int x=grid.size();
        int y=grid[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(grid, x-1, y-1);
    }
};