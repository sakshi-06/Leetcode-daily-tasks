class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        queue<int> q;
        vector<int> indegree(n+1,0);
        vector<vector<int>> graph(n+1);
        vector<int> ans;
        for(int i=0;i<p.size();i++){
            graph[p[i][0]].push_back(p[i][1]);
            indegree[p[i][1]]++;
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int t = q.front();
            q.pop();
            ans.push_back(t);
            for(auto &n:graph[t]){
                indegree[n]--;
                if(indegree[n]==0){
                    q.push(n);
                }
            }
        }
        if(ans.size()!=n) return {};
        reverse(ans.begin(), ans.end());
        return ans;
    }
};