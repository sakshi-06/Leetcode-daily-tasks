class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3)
        {
            return 0;
        }
        int diff=nums[1]-nums[0];
        int curr=0;
        int ans=0;
        for(int i=2;i<n;i++)
        {
            int curr_diff=nums[i]-nums[i-1];
            if(curr_diff==diff)
            {
                curr++;
            }
            else
            {
                diff=curr_diff;
                curr=0;
                
            }
            ans+=curr;
        }
        return ans;
    }
};