class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int count = 0;
        int result = 0;
        for (int i=0; i<nums.size(); i++){
            if (i == 0){count++;}
            else{
                if (nums[i] > nums[i-1]){
                    count++;
                }else{
                    result =max(result,count);
                    count = 1;
                }
            }
        }
        
        return max(result,count);
    }
};