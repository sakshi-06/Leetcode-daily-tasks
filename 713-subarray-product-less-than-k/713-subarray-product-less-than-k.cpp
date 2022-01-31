class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int ans=0;
        int j=0;
        int n=nums.size();
        int prod=1;
        for(int i=0;i<n;i++)
        {
            prod*=nums[i];
            while(prod>=k)
            {
                prod/=nums[j];
                j++;
            }
            ans+=(i-j+1);
        }
        return ans;
    }
};