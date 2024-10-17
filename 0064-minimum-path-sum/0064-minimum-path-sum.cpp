class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<int> dp(grid[0].size(), 0);
        for (int i = grid.size() - 1; i >= 0; i--) {
            for (int j = grid[0].size() - 1; j >= 0; j--) {
                if (i == grid.size() - 1 && j != grid[0].size() - 1)
                    dp[j] = grid[i][j] + dp[j + 1];
                else if (j == grid[0].size() - 1 && i != grid.size() - 1)
                    dp[j] = grid[i][j] + dp[j];
                else if (i != grid.size() - 1 && j != grid[0].size() - 1)
                    dp[j] = grid[i][j] + min(dp[j], dp[j + 1]);
                else
                    dp[j] = grid[i][j];
            }
        }
        return dp[0];
    }
};