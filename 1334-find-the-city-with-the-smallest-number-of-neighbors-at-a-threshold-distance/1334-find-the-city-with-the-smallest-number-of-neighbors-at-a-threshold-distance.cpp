class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int t) {
       vector<vector<int>> dist(n,vector<int>(n,10001));
        for(auto e:edges)
        {
            dist[e[0]][e[1]]=dist[e[1]][e[0]]=e[2];
        }
        for(int i=0;i<n;i++)
        {
            dist[i][i]=0;
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
        int res=n;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(dist[i][j]<=t)
                {
                    cnt++;
                }
            }
            if(cnt<=res)
            {
                res=cnt;
                ans=i;
            }
        }
        return ans;
    }
};