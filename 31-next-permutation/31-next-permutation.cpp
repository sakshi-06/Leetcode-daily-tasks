class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       int n=nums.size();
        int index1=0, index2=0;
        int i=0;
        for(i=n-2;i>=0;i--)
        {
            if(nums[i+1]>nums[i])
                break;
        }
        index1=i;
        if(i<0) reverse(nums.begin(), nums.end());
        else
        {
       for(i=nums.size()-1;i>index1;i--)
       {
           if(nums[i]>nums[index1])
           {
               index2=i;
               break;
           }
       }
        swap(nums[index1], nums[index2]);
        sort(nums.begin()+index1+1, nums.end());
    }
    }
};