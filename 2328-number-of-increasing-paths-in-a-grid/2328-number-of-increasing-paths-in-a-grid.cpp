class Solution {
public:
    int mod = 1e9+7;
    int solve(vector<vector<int>> &grid, vector<vector<int>> &dp,int i, int j, int prev){
        //check for boundary condition
        if(i<0 || j<0 || j>=grid[0].size() || i>=grid.size()) return 0;
        if(grid[i][j]<=prev) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        long long int ans=1;
        ans+=solve(grid, dp, i+1, j, grid[i][j])%mod;
        ans+=solve(grid, dp, i-1, j, grid[i][j])%mod;
        ans+=solve(grid, dp, i, j+1, grid[i][j])%mod;
        ans+=solve(grid, dp, i, j-1, grid[i][j])%mod;
        return dp[i][j]=ans%mod;
    }
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int> (m,-1));
        long long int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cnt+=solve(grid, dp, i, j, -1);
            }
        }
        return cnt%mod;
    }
};