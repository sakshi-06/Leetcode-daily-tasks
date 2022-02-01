class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
        }
        int start=0;
        int ans=1;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=1;
                ans=2;
                start=i;
            }
        }
        
        for(int k=3;k<=n;k++)
        {
            for(int i=0,j=i+k-1;j<n;i++,j++)
            {
                //int j=i+k-1;
                if(s[i]==s[j] && dp[i+1][j-1]==1)
                {
                    dp[i][j]=1;
                    ans=k;
                    start=i;
                }
            }
        }
        return s.substr(start,ans);
    }
};