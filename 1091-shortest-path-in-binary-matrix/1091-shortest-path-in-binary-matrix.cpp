class Solution {
public:
    bool isvalid(int n,int m,int i,int j,vector<vector<int>> &grid)
    {
        if(i<0||j<0||i>=n||j>=m||grid[i][j]!=0) return false;
        return true;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid.size()==0 || grid[0].size()==0) return 0;
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        if(n-1==0) return 1;
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n,vector<bool> (m,false));
        q.push({0,0});
        vis[0][0]=true;
        int ans=1;
        vector<int> dir[8]={{0,1},{0,-1},{-1,0},{1,0},{1,-1},{1,1},{-1,1},{-1,-1}};
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<8;i++)
            {
                int nx=x+dir[i][0];
                int ny=y+dir[i][1];
                 if(nx==n-1 && ny==m-1) return ans+1;
                if(isvalid(n,m,nx,ny,grid) && !vis[nx][ny])
                {
                    vis[nx][ny]=true;
                    q.push({nx,ny});
                }
            }
            }
            ans++;
        }
        return -1;
    }
};