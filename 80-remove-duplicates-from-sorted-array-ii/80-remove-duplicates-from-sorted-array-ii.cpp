class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return n;
        int idx=2;
        for(int i=2;i<n;i++)
        {
            if(nums[idx-2]!=nums[i])
            {
                nums[idx]=nums[i];
                idx++;
            }
        }
        return idx;
    }
};