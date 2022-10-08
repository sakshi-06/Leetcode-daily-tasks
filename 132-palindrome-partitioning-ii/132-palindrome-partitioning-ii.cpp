class Solution {
public:
    int dp[20001];
    bool ispal(string &s, int i,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int solve(string&s, int i, int j)
    {
        if(i>=j || ispal(s,i,j)) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=INT_MAX;
        for(int k=i;k<j;k++)
        {
            if(ispal(s, i, k))
            {
                int temp = solve (s, k+1, j) + 1;
                ans = min (ans, temp);
            }
        }
        return dp[i]=ans;
    }
    int minCut(string s) {
        int n=s.size();
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, n-1);
    }
};