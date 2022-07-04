class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string,double>> adj;
        vector<double> res(queries.size());
        for(int i=0;i<equations.size();i++)
        {
            adj[equations[i][0]].insert({equations[i][1],values[i]});
            adj[equations[i][1]].insert({equations[i][0],(double) 1/values[i]});
        }
        for(int i=0;i<queries.size();i++)
        {
            unordered_set<string> vis;
            res[i]=dfs(adj,queries[i][0],queries[i][1],vis);
        }
        return res;
        
    }
    double dfs(unordered_map<string,unordered_map<string,double>>&adj, string st, string end,unordered_set<string> vis)
    {
        if(adj.find(st)==adj.end()) return -1.0;
        if(adj[st].find(end)!=adj[st].end())
        {
            return adj[st][end];
        }
        vis.insert(st);
        
        for(auto i:adj[st])
        {
             if(!vis.count(i.first))
            {
                double ans=dfs(adj,i.first,end,vis);
                if(ans!=-1.0)
                    return (double)ans * (i.second);
            }   
        }
        return -1.0;
    }
};