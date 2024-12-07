class Solution {
public:
    int solve(int i, int j,int n,int m, vector<vector<int>> &dungeon, vector<vector<int>> &dp){
        if(i==n-1 && j==m-1){
            if(dungeon[i][j]>=0) return 1;
            else return -dungeon[i][j]+1;
        }
        if(i>=n || j>=m) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        int down = solve(i, j+1, n, m, dungeon, dp);
        int right = solve(i+1, j, n, m, dungeon, dp);
        dp[i][j] = min(down, right) - dungeon[i][j];
        if(dp[i][j]<=0) dp[i][j]=1;
        return dp[i][j];
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n =dungeon.size();
        int m = dungeon[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0, 0, n, m, dungeon, dp);
    }
};