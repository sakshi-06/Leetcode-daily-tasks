class Solution {
public:
    bool hasCycle(int x, vector<vector<int>> &graph, vector<bool> &visited,vector<bool> &recstack) { 
        
        visited[x] = true; 
        recstack[x]= true;
        
        for(int i : graph[x]) { 
            if(!visited[i]) { 
                if(hasCycle(i, graph, visited, recstack)) { 
                    return true;
                }
            } else if(recstack[i]) { 
                return true;
            }
        } 
        
        recstack[x] = false; 
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> safeNodes;  
        
        int V = graph.size();
        
        vector<bool> visited(V, false); 
        vector<bool> recstack(V, false);
        
        for(int i = 0; i < V; i++) { 
            if(!hasCycle(i, graph, visited, recstack)) { 
                safeNodes.push_back(i);
            } 
        }
        return safeNodes;
    }
    
};