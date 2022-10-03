class Solution {
public:
    int dp[101];
    int solve(string &s,int pos)
    {
      if(pos==s.size()) return 1;
      if(dp[pos]!=-1) return dp[pos];
        if(s[pos]=='0') return 0;
        int res=0;
        res=solve(s,pos+1);
        if(pos<s.size()-1 && (s[pos]=='1'|| s[pos]=='2' && s[pos+1]<'7')) res+=solve(s,pos+2);
        return dp[pos]=res;
    }
    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        return solve(s,0);
    }
};