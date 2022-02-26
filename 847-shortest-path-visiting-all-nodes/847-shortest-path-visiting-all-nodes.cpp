class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<bool>> vis(n,vector<bool> (1<<n));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            q.push({i,1<<i});
            vis[i][1<<i]=true;
        }
        int ans=0;
        while(!q.empty())
        {
            for(int sz=q.size();sz>0;sz--)
            {
                auto [u,mask]=q.front();
                q.pop();
                if(mask==(1<<n)-1) return ans;
                for(auto &v:graph[u])
                {
                    if (!vis[v][mask | 1<<v]) {
                        q.emplace(v, mask | 1<<v);
                        vis[v][mask | 1<<v] = true; 
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};