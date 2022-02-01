class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=0;
        int ans=0;
        int valley=0;
        int peak=0;
        while(i<prices.size()-1)
        {
            while(i<prices.size()-1 && prices[i]>=prices[i+1]) i++;
            valley=prices[i];
            while(i<prices.size()-1 && prices[i]<=prices[i+1]) i++;
            peak=prices[i];
            ans+=(peak-valley);
            //i++;
        }
        return ans;
    }
};