class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
       unordered_map<string,unordered_map<string,double>> adj;
        
        //create a adj list 
        createAdjList(adj,equations,values);
        
        vector<double> res(queries.size());
        //calculate result of every query
        for(int i=0;i<queries.size();i++)
        {
            unordered_set<string> visited;
            res[i]=dfs(queries[i][0],queries[i][1],visited,adj);
        }
        return res; 
    }
    double dfs(string start,string end,unordered_set<string>& visited,unordered_map<string,unordered_map<string,double>>& adj)
    {
        //we cant find the  given string
        if(adj.find(start)==adj.end())
            return -1.0;
        //if we have got our string end 
        if(adj[start].find(end)!=adj[start].end())
            return adj[start][end];
        visited.insert(start);
        //explore all possible paths 
        //if any one of them doesnot returns -1.0 we got our solution 
        for(auto i:adj[start])
        {
            //we dont want to revisit our previously visited strings
            if(!visited.count(i.first))
            {
                double ans=dfs(i.first,end,visited,adj);
                if(ans!=-1.0)
                    return (double)ans * (i.second);
            }       
        }
        return -1.0;
    }
    
    
    
    
    
    void createAdjList(unordered_map<string,unordered_map<string,double>>& adj,vector<vector<string>>&  equations,vector<double>& values)
    {
        for(int i=0;i<equations.size();i++)
        {
            string from=equations[i][0];
            string to=equations[i][1];
            adj[from].insert({to,values[i]});
            adj[to].insert({from,(double)1/values[i]});
        }
            
    }
};