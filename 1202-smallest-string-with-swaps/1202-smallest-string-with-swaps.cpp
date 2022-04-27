class Solution {
public:
    static const int N= 100001;
    vector<int> adj[N];
    bool vis[N];
    void dfs(string &s,int vertex, vector<char> &c,vector<int> &indices)
    {
        c.push_back(s[vertex]);
        indices.push_back(vertex);
        vis[vertex]=true;
        for(int a:adj[vertex])
        {
            if(!vis[a])
            {
                dfs(s,a,c,indices);
            }
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        for(vector<int> e:pairs)
        {
            int src=e[0];
            int dest=e[1];
            adj[src].push_back(dest);
            adj[dest].push_back(src);
        }
        for(int i=0;i<s.size();i++)
        {
            if(!vis[i])
            {
                vector<char> c;
                vector<int> indices;
                dfs(s,i,c,indices);
                sort(c.begin(),c.end());
                sort(indices.begin(),indices.end());
                for(int index=0;index<c.size();index++)
                {
                    s[indices[index]]=c[index];
                }
            }
        }
        return s;
    }
};