class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result=nums.size();
        int i=0;
        for(auto n:nums)
        {
            result ^=n;
            result^=i;
            i++;
        }
        return result;
    }
};