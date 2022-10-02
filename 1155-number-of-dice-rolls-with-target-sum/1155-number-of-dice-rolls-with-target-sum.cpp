class Solution {
public:
    int dp[31][10001];
    int mod=1e9+7;
    int solve(int dice, int faces,int target)
    {
        if(dice==0 && target==0) return 1;
        if(dice<=0 || target<=0) return 0;
        if(dp[dice][target]!=-1) return dp[dice][target];
        int res=0;
        for(int i=1;i<=faces;i++)
        {
            res=(res+solve(dice-1,faces, target-i)%mod)%mod;
        }
        return dp[dice][target]=res;
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp, -1,sizeof(dp));
        return solve(n,k,target);
    }
};