class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int i=0;
        int j=n;
        vector<int> a;
        while(i<=n && j<=nums.size()-1)
        {
            a.push_back(nums[i++]);
            a.push_back(nums[j++]);
        }
        return a;
    }
};