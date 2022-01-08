class Solution {
public:
    int dp[71][71][71];
    int dy[3] = {0, -1, 1};
    int solve(vector<vector<int>>& grid, int r,int c1,int c2)
    {
        if(r==grid.size())
        {
            return 0;
        }
        if(c1<0 || c2<0|| c1>=grid[0].size()|| c2>=grid[0].size())
        {
            return INT_MIN;
        }
        if(dp[r][c1][c2]!=-1) return dp[r][c1][c2];
        int maxAns=0;
        for(int k=0;k<3;k++)
        {
            for(int j=0;j<3;j++)
            {
                maxAns = max(maxAns, solve(grid,r+1,c1+dy[k],c2+dy[j]));
            }
        }
        maxAns+= (c1==c2) ? grid[r][c1]: grid[r][c1]+grid[r][c2];
        return dp[r][c1][c2]=maxAns;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1,sizeof(dp));
        int m=grid[0].size();
        return solve(grid,0,0,m-1);
    }
};