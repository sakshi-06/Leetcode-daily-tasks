class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> graph(n+1);
        for(int i=0;i<trust.size();i++)
        {
            graph[trust[i][1]].push_back(trust[i][0]);
        }
        int ans1=-1,ans2=0;
        for(int i=1;i<=n;i++)
        {
            if(graph[i].size()==n-1)
            {
                ans1=i;
            }
        }
        vector<bool> vis(n+1,false);
        for(int i=1;i<=n;i++)
        {
            for(auto x:graph[i])
            {
                vis[x]=true;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==false) ans2=i;
        }
        if(ans1==ans2) return ans1;
        return -1;
    }
};