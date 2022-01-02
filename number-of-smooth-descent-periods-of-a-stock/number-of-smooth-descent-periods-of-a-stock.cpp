class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans=0;
        long long j=0,i=0;
        while(i<prices.size())
        {
           j=i;
            while(i<prices.size()-1 &&prices[i]-prices[i+1]==1)
            {
                i++;
            }
            long long len=(i-j+1);
            ans+=((len)*(len+1)) /2;
            i++;
           // j=i;
        }
        return ans;
    }
};