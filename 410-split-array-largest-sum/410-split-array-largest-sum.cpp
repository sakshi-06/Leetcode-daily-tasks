class Solution {
public:
    bool check(vector<int> &nums,int cuts,int max_sum)
    {
        int sum=0;
        for(auto &x:nums)
        {
            if(x>max_sum)
            {
                return false;
            }
            else if(x+sum<=max_sum)
            {
                sum+=x;
            }
            else
            {
                cuts--;
                sum=x;
                if(cuts<0) return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int m) {
        int l=0,r=0;
        for(int i=0;i<nums.size();i++)
        {
            r+=nums[i];
        }
        int ans=0;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(check(nums,m-1,mid)) 
            {
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};