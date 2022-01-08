class Solution {
public:
    int dp[100005][3];
    unordered_map<int,int> mp;
    int minSumOfLengths(vector<int>& arr, int target) {
        memset(dp, 127,sizeof(dp));
        int n=arr.size();
        mp[0]=0;
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=0;
        }
        int currsum=0;
        for(int i=1;i<=n;i++)
        {
            currsum+=arr[i-1];
            mp[currsum]=i;
            int d=-1;
            if(mp.count(currsum-target)) d=mp[currsum-target];
            for(int j=1;j<=2;j++)
            {
                dp[i][j]=min(dp[i][j],dp[i-1][j]);
                if(d!=-1)
                {
                    dp[i][j]=min(dp[i-1][j], dp[d][j-1]+(i-d));
                }
            }
        }
        if(dp[n][2]>1e9) return -1;
        return dp[n][2];
    }
};