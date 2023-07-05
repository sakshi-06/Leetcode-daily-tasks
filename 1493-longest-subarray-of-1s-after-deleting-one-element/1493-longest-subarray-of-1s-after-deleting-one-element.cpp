class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0,j=0;
        int ans=0;
        int skip=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0) skip++;
            if(skip>1)
            {
                if(nums[j++]==0) skip--;
            }
            ans=max(ans,i-j);
        }
        return ans;
    }
};