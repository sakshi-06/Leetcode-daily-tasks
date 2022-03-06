class Solution {
public:
     int mod=1e9+7;   
    int countOrders(int n) {
      long ans=1;
        for(int i=1;i<=n;i++)
        {
            ans=ans*i;
            ans=ans*(2*i-1);
            ans=ans%mod;
        }
        
        return ans;
    }
};