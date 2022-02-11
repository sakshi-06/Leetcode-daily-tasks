class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        set<vector<int>> s;
        vector<vector<int>> v;
        for(int i=0;i<n-2;i++)
        {
            int x=nums[i];
            int l=i+1,r=n-1;
            while(l<r)
            {
                int sum=x+nums[l]+nums[r];
                if(sum>0)r--;
                else if(sum<0) l++;
                else
                {
                    s.insert({x, nums[l],nums[r]});
                    l++;
                    r--;
                    
                }
            }
        }
         auto it=s.begin();
        while(it!=s.end()){
            v.push_back(*it);  
            it++;
        }
        return v;      
    }
};