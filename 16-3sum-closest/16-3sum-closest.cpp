class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff=INT_MAX;
        int ans=0;
        for(int i=0;i<nums.size()&& diff!=0;i++)
        {
            int lo=i+1;
            int hi=nums.size()-1;
            while(lo<hi)
            {
                int sum=nums[i]+nums[lo]+nums[hi];
                if(abs(diff)>abs(target-sum))
                {
                    diff=target-sum;
                }
                if(sum<target) lo++;
                else hi--;
            }
        }
        return target-diff;
    }
};