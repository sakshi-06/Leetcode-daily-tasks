class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(is_sorted(nums.begin(),nums.end())) return 0;
        if(nums.size()==1) return 0;
        vector<int> n=nums;
        sort(n.begin(),n.end());
        int r=nums.size()-1, l=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=n[i])
            {
                r=min(r,i);
                l=max(l,i);
            }
        }
        return l-r+1;
    }
};