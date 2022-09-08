class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int> &nums,vector<int> &temp, int idx)
    {
         if(idx >= nums.size()) {
        ans.push_back(temp);
        return;
        }
           
    //push the element of current index to the value of current subset
    temp.push_back(nums[idx]);
           // call the function to push next element
    solve(nums,temp,idx+1);
           // remove the pushed element for next iterations
    temp.pop_back();
    
           
    while(idx+1 < nums.size() && nums[idx] == nums[idx+1]) idx++;
    // call the function and find next subsets 
    solve(nums,temp,idx+1);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(),nums.end());
        int idx=0;
        solve(nums,temp,0);
        return ans;
    }
};