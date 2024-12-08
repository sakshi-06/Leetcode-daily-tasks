class Solution {
public:
    int dp[51][51][51];
    vector<vector<int>> dir ={{0, -1},{0,1},{-1,0},{1,0}};
    int mod = 1e9+7;
    int solve(int i, int j, int m, int n, int maxMove){
        
        if(i<0 || j<0|| i>=m || j>=n)
        {
            return 1;
        }
        if(maxMove==0) return 0;
        if(dp[i][j][maxMove]!=-1) return dp[i][j][maxMove];
        int res =0;
        for(int d=0;d<dir.size();d++){
            int n_x = i+dir[d][0];
            int n_y = j+dir[d][1];
             res += solve(n_x, n_y, m, n, maxMove-1);
                res=res%mod;
        }
        return dp[i][j][maxMove] = res%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return solve(startRow, startColumn, m ,n , maxMove);
    }
};