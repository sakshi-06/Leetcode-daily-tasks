class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int min_temp = nums[0];
        int max_temp = nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            int temp = min_temp;
            min_temp= min({min_temp * nums[i], nums[i], max_temp*nums[i]});
            max_temp = max({nums[i], max_temp*nums[i], temp *nums[i]});
            ans= max(ans, max_temp);
        }
        return ans;
    }
};