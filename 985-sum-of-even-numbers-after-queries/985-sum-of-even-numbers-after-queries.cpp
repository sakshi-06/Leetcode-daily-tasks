class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
       int sum=0;
       vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0)
            {
                sum+=nums[i];
            }
        }
        for(auto q:queries)
        {
            if(nums[q[1]]%2==0)
            {
                sum-=nums[q[1]];
            }
            nums[q[1]]+=q[0];
            if(nums[q[1]]%2==0) sum+=nums[q[1]];
            res.push_back(sum);
        }
        return res;
    }
};