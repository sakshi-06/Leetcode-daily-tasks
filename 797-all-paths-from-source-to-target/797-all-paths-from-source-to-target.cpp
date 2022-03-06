class Solution {
public:
    vector<vector<int>> ans;
    void solve(int u,int p,vector<vector<int>> &graph,int n,vector<int> &temp)
    {
        if(u==n-1)
        {
            //temp.push_back(u);
            ans.push_back(temp);
            return;
        }
        for(auto &v:graph[u])
        {
            if(v!=p)
            {
                temp.push_back(v);
                solve(v,u,graph,n,temp);
                temp.pop_back();
            }
        }
        return ;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> temp;
        int n=graph.size();
        temp.push_back(0);
        solve(0,-1,graph,n,temp);
        return ans;
    }
};