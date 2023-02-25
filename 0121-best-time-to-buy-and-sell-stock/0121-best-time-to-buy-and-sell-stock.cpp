class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m=INT_MAX;
        int ans=0;
        int profit=0;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<m)
            {
                m=prices[i];
            }
            profit=prices[i]-m;
            ans=max(ans,profit);
        }
        return ans;
        
    }
};