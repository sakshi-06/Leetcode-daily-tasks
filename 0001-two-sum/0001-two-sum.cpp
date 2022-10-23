class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> numPosMap;
        for(int i=0;i<nums.size();i++)
        {
            if(numPosMap.find(target-nums[i])!=numPosMap.end())
            {
                return {numPosMap[target-nums[i]],i};
            }
            numPosMap[nums[i]]=i;
        }
        return {-1,-1};
    }
};