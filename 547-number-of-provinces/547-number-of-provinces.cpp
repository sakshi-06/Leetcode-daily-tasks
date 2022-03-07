class Solution {
public:
   // vector<int> parent;
    int find_parent(int u,vector<int> &parent)
    {
        return parent[u]==u?parent[u]:find_parent(parent[u],parent);
    }
    
    int findCircleNum(vector<vector<int>>& g) {
        int n=g.size();
        vector<int> parent(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        int ans=n;
        for(int i=0;i<g.size();i++)
        {
            for(int j=i+1;j<g[i].size();j++)
            {
                if(g[i][j]==1)
                {
                    int p1=find_parent(i,parent);
                    int p2=find_parent(j,parent);
                    if(p1!=p2)
                    {
                        parent[p1]=p2;
                        ans--;
                    }
                }
            }
        }
        return ans;
    }
};