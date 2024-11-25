class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
       vector<vector<int>> adj(n + 1);
        vector<int> indeg(n + 1);
        // earliest start time for course
        vector<int> start(n + 1);
        
        for (auto& e : relations) {
            adj[e[0]].push_back(e[1]);
            indeg[e[1]]++;
        }

        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        int ans = 0;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            int finish = start[node] + time[node - 1];
            ans = max(ans, finish);
            for (auto next : adj[node]) {
                start[next] = max(start[next], finish);
                if (--indeg[next] == 0) {
                    q.push(next);
                }
            }
        }

        return ans;
        
    }
};