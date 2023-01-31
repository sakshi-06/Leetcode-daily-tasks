class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<vector<int>> p;
        for(int i=0;i<scores.size();i++)
        {
            p.push_back({ages[i], scores[i]});
        }
        sort(p.begin(), p.end(), greater<>());
        int n=ages.size();
        vector<int> dp(n); //dp[i] shows the max score you get by having an score and ages till ith index
    
        int ans=0;
        for(int i=0;i<n;i++)
        {
            dp[i]=p[i][1];
            for(int j=0;j<i;j++)
            {
                if(p[j][1]>=p[i][1])  // age of j >=age of i
                {
                    dp[i]=max(dp[i], dp[j]+p[i][1]);
                }
            }
            ans=max(ans, dp[i]);
        }
        return ans;
    }
};