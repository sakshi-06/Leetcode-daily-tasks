class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
     int n=nums.size();
        vector<int> sum;
        sum.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            sum.push_back(sum.back()+nums[i]);
        }
        return sum;
    }
};