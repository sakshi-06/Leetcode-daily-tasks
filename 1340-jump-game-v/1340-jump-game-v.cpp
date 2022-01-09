class Solution {
public:
    int dp[10001];
    int solve(int ind,vector<int>&arr, int d)
    {
        if(dp[ind]!=-1) return dp[ind];
        dp[ind]=0;
        for(int i=ind+1;i<arr.size() && i<=ind+d && arr[i]<arr[ind];i++)
        {
            dp[ind]=max(dp[ind],1+solve(i,arr,d));
        }
        for(int i=ind-1;i>=0 && i>=ind-d && arr[i]<arr[ind];i--)
        {
            dp[ind]=max(dp[ind],1+solve(i,arr,d));
        }
        return dp[ind];
    }
    int maxJumps(vector<int>& arr, int d) {
        memset(dp, -1, sizeof(dp));
        int result=0;
        for(int i=0;i<arr.size();i++)
        {
            result=max(result,1+solve(i,arr,d));
        }
        return result;
    }
};