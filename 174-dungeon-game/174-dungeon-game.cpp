class Solution {
public:
    int dp[201][201];
    int solve(vector<vector<int>> &grid, int i,int j)
    {
        if(i==grid.size()-1 && j==grid[0].size()-1)
        {
            if(grid[i][j]<=0)
            {
                return abs(grid[i][j])+1;
            }
            else return 1;
        }
        
        if(i>=grid.size() || j>=grid[0].size()) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        ans=min(solve(grid,i+1,j),solve(grid,i,j+1))-grid[i][j];
        if(ans<=0) dp[i][j]=1;
        else dp[i][j]=ans;
        return dp[i][j];
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        memset(dp, -1, sizeof(dp));
        return solve(dungeon, 0, 0);
    }
};