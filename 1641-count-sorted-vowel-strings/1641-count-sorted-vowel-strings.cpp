class Solution {
public:
    int dp[51][6];
    int solve(int w_pos,int pos,int n)
    {
        if(pos==n) return 1;
        if(dp[pos][w_pos]!=-1) return dp[pos][w_pos];
        long long int res=0;
        for(int i=w_pos;i<=5;i++)
        {
            res+=solve(i,pos+1,n);
        }
        return dp[pos][w_pos]=res;
    }
    int countVowelStrings(int n) {
        memset(dp, -1, sizeof(dp));
        long long int ans=0;
        for(int i=1;i<=5;i++)
        {
            ans+=solve(i,1,n);
        }
        return ans;
    }
};