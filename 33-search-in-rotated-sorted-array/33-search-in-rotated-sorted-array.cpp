class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            if(nums[mid]>=nums[l])
            {
                if(target<=nums[mid] && target>=nums[l])
                {
                    r=mid;
                }
                else l=mid+1;
            }
            else
            {
                if(target<=nums[r] && target>=nums[mid])
                {
                    l=mid+1;
                }
                else r=mid;
            }
        }
        return -1;
    }
};