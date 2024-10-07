class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &component,vector<bool> &vis ){
        vis[node] = true;
        component.push_back(node);
        for(auto neigh:adj[node]){
            if(!vis[neigh]){
                dfs(neigh, adj, component,vis);
            }
        }
        return;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int x = edges[i][0];
            int y = edges[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<bool> visited(n, false);
    int completeComponentsCount = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            // Find the current connected component
            vector<int> component;
            dfs(i, adj, component, visited);

            // Step 3: Check if the component is complete
            int k = component.size();   // Number of vertices in the component
            int m = 0;                  // Number of edges in the component

            // Count the edges in the component
            for (int node : component) {
                m += adj[node].size();
            }
            m /= 2; // Each edge is counted twice, so divide by 2

            // For a complete component, the number of edges should be k * (k - 1) / 2
            if (m == k * (k - 1) / 2) {
                completeComponentsCount++;
            }
        }
    }

    return completeComponentsCount;
    }
};