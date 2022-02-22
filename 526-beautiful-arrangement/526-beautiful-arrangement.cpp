class Solution {
public:
    int res=0;
    vector<bool> vis;
    void dfs(int n,int pos)
    {
        if(pos>n)
        {
            res++;
        }
        for(int i=1;i<=n;i++)
        {
            if(!vis[i] &&(pos%i==0 || i%pos==0))
            {
                vis[i]=true;
                dfs(n,pos+1);
                vis[i]=false;
            }
        }
        
    }
    int countArrangement(int n) {
        vis.resize(n+1,false);
        dfs(n,1);
        return res;
    }
};