class Solution {
public:
    int solve(string &s, int i, vector<int> &dp){
        if(i==s.size()) return 1;
        if(dp[i]!=-1) return dp[i];
        if(s[i]=='0') return 0;
        int ans=solve(s, i+1, dp);
        if(i+1<s.size() && (s[i]=='1'|| s[i]=='2' && (s[i+1]<'7'))){
            ans+=solve(s, i+2, dp);
        }
        return dp[i]=ans;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return solve(s,0, dp);
    }
};