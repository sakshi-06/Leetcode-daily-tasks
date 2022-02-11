class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=nums[0], result=nums[0];
        int i;
        for( i=1;i<nums.size();i++)
        {
            sum=max(nums[i],sum+nums[i]);
            result=max(sum,result);
        }
        return result;
    }
};