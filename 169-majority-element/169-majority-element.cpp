class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0;
        sort(nums.begin(),nums.end());
        int last=nums[0];
        int ans=0;
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==last)
            {
                cnt++;
                if(cnt>ans)
                {
                    ans=max(ans,cnt);
                    res=nums[i];
                }
            }
            else 
            {
                cnt=1;
                last=nums[i];
            }
        }
        return res;
    }
};