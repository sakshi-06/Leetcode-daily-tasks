class Solution {
public:
    bool check(long long x1, long long y1, long long x2, long long y2, long long d) {
        long long x = (x1-x2) * (x1-x2);
        long long y = (y1-y2) * (y1-y2);
        
        return (x + y  <= d * d);
    }
    void dfs(int u,vector<bool> &vis,vector<int> graph[],int &cnt)
    {
        cnt++;
        vis[u]=true;
        for(auto &v:graph[u])
        {
            if(vis[v]==false )
            {
                dfs(v,vis,graph,cnt);
            }

        }
        return ;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int ans=0;
        int n=bombs.size();
        vector<int> graph[n];
        for(int i=0;i<bombs.size();i++)
        {
            int x=bombs[i][0];
            int y=bombs[i][1];
            long long int r=bombs[i][2];
            for(int j=0;j<bombs.size();j++)
            {
               if(i != j && check(bombs[i][0], bombs[i][1], bombs[j][0], bombs[j][1], bombs[i][2])) {
                    graph[i].push_back(j);
                }  
            }
        }
        for(int i=0;i<n;i++)
        {
            vector<bool> vis(n,false);
            int cnt=0;
            vis[i]=true;
            //cout<<graph[i].size()<<" ";
            //cout<<cnt<<" ";
            dfs(i,vis,graph,cnt);
           // cout<<cnt<<" ";
            ans=max(ans,cnt);
        }
        return ans;
    }
};