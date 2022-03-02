class Solution {
public:
    bool dfs(int i, int j,vector<vector<int>> &grid1, vector<vector<int>> &grid2, bool &ans)
    {
        int n=grid2.size();
        int m=grid2[0].size();
        if(i<0||j<0||i>=n||j>=m||grid2[i][j]!=1) return true;
        if(grid1[i][j]!=1) ans= false;
        grid2[i][j]=2;
        dfs(i+1,j,grid1,grid2, ans);
        dfs(i,j+1,grid1,grid2, ans);
        dfs(i-1,j,grid1,grid2,ans);
        dfs(i,j-1,grid1,grid2,ans);
        return ans;
        
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size();
        int m=grid1[0].size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid1[i][j]==1 && grid2[i][j]==1)
                {
                   bool ans=true;
                    if(dfs(i,j,grid1,grid2, ans)) cnt++;
                }
            }
        }
        return cnt;
    }
};