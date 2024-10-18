class Solution {
public:
    int mod=1e9+7;
    int dp[51][51][51];
    int dir[4][4]={{-1,0},{1,0},{0,-1},{0,1}};
    int solve(int i,int j,int maxmove,int m,int n)
    {
        if(i<0 || j<0|| i>=m || j>=n)
        {
            return 1;
        }
        if(maxmove==0) return 0;
        if(dp[i][j][maxmove]!=-1) return dp[i][j][maxmove];
        int res=0;  //final result
       for(auto x:dir) //visit all 4 directions
       {
           res+=solve(i+x[0],j+x[1],maxmove-1,m,n); 
           res%=mod;
       }
        return dp[i][j][maxmove]=res%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return solve(startRow, startColumn, maxMove,m,n);
    }
};