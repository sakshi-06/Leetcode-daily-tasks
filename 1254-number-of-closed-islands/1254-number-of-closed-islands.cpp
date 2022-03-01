class Solution {
public:
    void dfs(vector<vector<int>> &grid,int i,int j,bool &check)
    {
        if(i<0|| j<0|| i>=grid.size()|| j>=grid[0].size())
        {
            check= false;
            return ;
        }
        if(grid[i][j]!=0) return;
        grid[i][j]=2;
        dfs(grid,i+1,j,check);
        dfs(grid,i-1,j,check);
        dfs(grid,i,j+1,check);
        dfs(grid,i,j-1,check);
    }
    int closedIsland(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    bool check=true;
                    dfs(grid,i,j,check);
                    if(check) ans++;
                }
            }
        }
        return ans;
    }
};