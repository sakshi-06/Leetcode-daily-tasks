class Solution {
public:
    int dp[501][501];
    int solve(vector<int> &s, int i, int time)
    {
        if(i>=s.size()) return 0;
        if(dp[i][time]!=-1) return dp[i][time];
        int ans1 = s[i] * time + solve(s, i + 1, time + 1);
        int ans2 = solve(s, i + 1, time);
        return dp[i][time] = max(0, max(ans1, ans2));
    }
    int maxSatisfaction(vector<int>& s) {
       int n=s.size();
        sort(s.begin(), s.end());
       memset(dp, -1, sizeof(dp));
        return solve(s, 0, 1);
    }
};