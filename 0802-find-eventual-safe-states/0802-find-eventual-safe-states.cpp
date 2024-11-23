class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> outdegree(n,0);
        queue<int> q;
        vector<int> ans;
        vector<vector<int>> reverse_g(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                reverse_g[graph[i][j]].push_back(i);
            }
            outdegree[i]=graph[i].size();
            if(outdegree[i]==0){
                q.push(i);
                ans.push_back(i);
            }
        }
            while(!q.empty()){
                int t= q.front();
                q.pop();
                for(auto &n:reverse_g[t]){
                    outdegree[n]--;
                    if(outdegree[n]==0){
                q.push(n);
                ans.push_back(n);
            }
                }
            }
        sort(ans.begin(),ans.end());
        return ans;
        }
};