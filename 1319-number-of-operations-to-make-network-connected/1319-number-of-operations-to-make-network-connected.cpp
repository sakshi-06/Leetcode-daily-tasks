class Solution {
public:
    int find_parent(int u,vector<int> &parent)
    {
        return parent[u]==u?u:find_parent(parent[u],parent);
    }
    
    int makeConnected(int n, vector<vector<int>>& c) {
      int k=c.size();
        vector<int> parent(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
      if(k<n-1) return -1;
      int ans=n;
        for(int i=0;i<c.size();i++)
        {
            int p1=find_parent(c[i][0],parent);
            int p2=find_parent(c[i][1],parent);
            if(p1!=p2)
            {
                parent[p1]=p2;
                ans--;
            }
        }
        return ans-1;
        
    }
};