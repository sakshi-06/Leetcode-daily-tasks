class Solution {
public:
    void solve(vector<vector<int>>& graph, vector<int> &res, vector<vector<int>> &ans, int n, int curr, int parent){
        if(curr ==n-1) {
            ans.push_back(res);
            return ;
        }
        for(auto &neigh: graph[curr]){
            if(neigh != parent){
               res.push_back(neigh);
            solve(graph, res,ans, n, neigh, curr);
            res.pop_back(); 
            }
            
        }
        return ;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> res;
    vector<vector<int>> ans;
        int n = graph.size();
        int m = graph[0].size();
        res.push_back(0);
        solve(graph, res,ans, n, 0, -1);
        return ans;
    }
};