class Solution {
public:
    int countzeros(string &s){
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0') ans++;
        }
        return ans;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int ans=0;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i=0;i<strs.size();i++){
            int cntZeros = countzeros(strs[i]);
            int cntOnes = strs[i].size()-cntZeros;
            for(int z = m; z>=cntZeros;z--){
                for(int o =n;o>=cntOnes;o--){
                    dp[z][o] = max(1+dp[z-cntZeros][o-cntOnes], dp[z][o]);
                }
            }
        }
        return dp[m][n];
    }
};