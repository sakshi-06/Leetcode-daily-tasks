class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(color[i]!=-1)
            {
                continue;
            }
            color[i]=0;
            q.push(i);
            while(!q.empty())
            {
                int u=q.front();
                q.pop();
                for(auto &v:graph[u])
                {
                    if(color[v]==color[u])
                    {
                        return false;
                    }
                    else if(color[v]==-1)
                    {
                        color[v]=1-color[u];
                        q.push(v);
                    }
                }
            }
        }
        return true;
    }
};