class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
         vector<int> dir[4]={{0,1},{0,-1},{-1,0},{1,0}};
        vector<vector<int>> dist(mat.size(), vector<int>(mat[0].size(),-1));
        queue<pair<int,int>> q;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        while(!q.empty())
        {
            pair<int,int> curr=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int x=curr.first+dir[i][0];
                int y=curr.second+dir[i][1];
                if(x>=0 &&y>=0&&x<mat.size()&&y<mat[0].size()&&dist[x][y]==-1&&mat[x][y]==1)
                {
                    dist[x][y]=dist[curr.first][curr.second]+1;
                    q.push({x,y});
                }
            }
        }
        return dist;
    }
};