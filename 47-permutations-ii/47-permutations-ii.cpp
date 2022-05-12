class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> &v, int n, vector<int> &nums)
    {
        if(v.size()==n)
        {
            if(find(ans.begin(),ans.end(),v) == ans.end()) ans.push_back(v);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=INT_MIN)
            {
                v.push_back(nums[i]);
                int temp=nums[i];
                nums[i]=INT_MIN;
                solve(ans, v, n,nums);
                nums[i]=temp;
                v.pop_back();
            }
                
        }
        return ;
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        vector<int> v;
        // vis.resize(n, false);
        vector<vector<int>> ans;
        solve(ans,v,n,nums);
        return ans;
    }
};