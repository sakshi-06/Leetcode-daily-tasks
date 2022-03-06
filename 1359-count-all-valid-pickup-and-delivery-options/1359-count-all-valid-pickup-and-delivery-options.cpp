class Solution {
public:
     int mod=1e9+7;
        long long dp[501][501];
    long long solve(int unpicked,int undelievered)
    {
        if(unpicked==0 && undelievered==0)
        {
            return 1;
        }
        if(unpicked<0 || undelievered<0|| undelievered<unpicked)
        {
            return 0;
        }
        if(dp[unpicked][undelievered])
        {
            return dp[unpicked][undelievered];
        }
        long long ans=0;
        ans+= unpicked * solve(unpicked-1, undelievered);
        ans%=mod;
        ans+=(undelievered - unpicked) * solve(unpicked, undelievered -1);
        ans %=mod;
        return dp[unpicked][undelievered]=ans;
    }
    int countOrders(int n) {
      memset(dp, 0,sizeof(dp));
        return solve(n,n);
        
    }
};