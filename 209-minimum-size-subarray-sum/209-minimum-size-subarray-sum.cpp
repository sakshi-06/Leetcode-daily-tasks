class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start=0, sum=0, ans=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            while(sum>=target)
            {
                ans=min(ans, i+1-start);
                sum-=nums[start];
                start++;
            }
        }
        return ans!=INT_MAX?ans:0;
    }
};