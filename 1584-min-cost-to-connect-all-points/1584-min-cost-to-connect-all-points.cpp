class Solution {
public:
    void merge(int u,int v,int parent[])
    {
        int p=parent[u];
        int q=parent[v];
        parent[p]=q;
    }
    int find(int u,int parent[])
    {
        if(parent[u]==u) return u;
        return parent[u]=find(parent[u],parent);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<int> dist;
        int n=points.size();
        int parent[n];
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        vector<vector<int>> graph;
        for(int i=0;i<points.size();i++)
        {
            for(int j=i;j<points.size();j++)
            {
                int d=abs(points[j][0]-points[i][0])+abs(points[j][1]-points[i][1]);
                graph.push_back({d,i,j});
            }
        }
        sort(graph.begin(),graph.end());
        int cnt=0;
        int ans=0;
        for(int i=0;i<graph.size();i++)
        {
            int u=graph[i][1];
            int v=graph[i][2];
            int p1=find(u,parent);
            int p2=find(v,parent);
            if(p1==p2)
            {
                continue;
            }
            cnt++;
            ans+=graph[i][0];
            merge(u,v,parent);
            if(cnt==n-1)
            {
                return ans;
            }
        }
        return ans;
    }
};