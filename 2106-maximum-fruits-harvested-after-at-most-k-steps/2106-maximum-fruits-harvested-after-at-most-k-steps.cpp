class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startpos, int k) {
        startpos++;
        int n=2e5+2;
        vector<int> presum(n+1,0);
        for(auto &it:fruits)
        {
            presum[it[0]+1]=it[1];
        }
        for(int i=1;i<n;i++)
        {
            presum[i]+=presum[i-1];
        }
        int l=0,r=0;
        int ans=0;
        for(r=startpos;r<n && r<=startpos+k;r++)
        {
            l=min(startpos, startpos-(k-2*(r-startpos)));
            l=max(1,l);
            ans=max(ans,presum[r]-presum[l-1]);
        }
        for(l=startpos;l>0 && l>=startpos-k;l--)
        {
            r=max(startpos,startpos+(k-2*(startpos-l)));
            r=min(n-1,r);
            ans=max(ans,presum[r]-presum[l-1]);
        }
        return ans;
    }
};