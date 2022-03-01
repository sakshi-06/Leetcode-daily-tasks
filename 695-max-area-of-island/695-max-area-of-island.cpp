class Solution {
public:
    void dfs(vector<vector<int>> &grid,int i,int j,int &sum)
    {
        if(i<0|| j<0|| i>=grid.size()|| j>=grid[0].size()||grid[i][j]!=1)
        {
            return ;
        }
        grid[i][j]=2;
        sum++;
        dfs(grid,i+1,j,sum);
        dfs(grid,i-1,j,sum);
        dfs(grid,i,j+1,sum);
        dfs(grid,i,j-1,sum);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    int sum=0;
                    dfs(grid,i,j,sum);
                    ans=max(ans,sum);
                }
            }
        }
        return ans;
    }
};