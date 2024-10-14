class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n); //for storing prefix sum    
        unordered_map<int,long long> mp; //for strong index with prefix sum till then

        prefix[0] = (long long)nums[0];
        for(int i=1 ; i<n ; i++)
        {   
            prefix[i] = prefix[i-1] + (long long)nums[i];
        }
        long long ans = LLONG_MIN;

        for(int i=0 ; i<n ; i++)
        {
            //opening modulus we get
            int diff1 = nums[i] - k;
            int diff2 = nums[i] + k;

            //diff1 found updating answer with range sum
            if(mp.find(diff1) != mp.end())
            {
                ans = max(ans, prefix[i] - mp[diff1] + diff1);
            }
            //diff2 found updating answer with range sum
            if(mp.find(diff2) != mp.end())
            {
                ans = max(ans, prefix[i] - mp[diff2] + diff2);
            }

            //if map already have nums[i] then there might be two cases when the best answer
            // we get is with current index i or mp[nums[i]] (kadane's algo),
            // now if my mp[nums[i]] is greater than prefix i then we got to know that
            // there are some negative values in that range so we modify it to the current prefix
            // which is smaller than existing prefix
            if(mp.find(nums[i]) != mp.end())
            {
                mp[nums[i]] = min(mp[nums[i]], prefix[i]);
            }
            // if the number is not foung then pushing the prefix sum till i
            else
            {
                mp[nums[i]] = prefix[i];
            }
        }
        //no such subarray found then return 0
        return ans != LLONG_MIN ? ans : 0;
    }
};