class Solution {
public:
    bool solve(string &s, unordered_set<string> &st,int i, vector<int> &dp){
        if(i==s.size()) return true;
        if(i>s.size()) return false;
        if(dp[i]!=-1) return dp[i];
        for(int idx =i;idx<s.size();idx++){
            if(st.find(s.substr(i,idx-i+1)) !=st.end() && solve(s, st, idx+1,dp)){
                return dp[i]=true;
            }
        }
        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        int n=s.size();
        vector<int> dp(n , -1);
        return solve(s, st,0, dp);
    }
};