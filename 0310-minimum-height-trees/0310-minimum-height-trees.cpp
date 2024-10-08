class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==0) return {};
        if(n==1) return {0};
        vector<int> indegree(n);
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back({v});
            adj[v].push_back({u});
            indegree[u]++;
            indegree[v]++;
        }
        //topological sort
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==1) q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            ans.clear();
            int s =q.size();
            while(s--){
                int n =q.front();
                q.pop();
                ans.push_back(n);
                for(auto x:adj[n]){
                    indegree[x]--;
                    if(indegree[x]==1){
                        q.push(x);
                    }
                }
            }
        }
        return ans;
    }
};