class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()==0) return {};
        vector<string> ans;
        vector<pair<int,int>> p;
        p.push_back({nums[0],nums[0]});
        for(int i=1;i<nums.size();i++)
        {
            if(p.back().second+1==nums[i])
            {
               p.back().second=nums[i]; 
            }
            else
            {
                p.push_back({nums[i],nums[i]});
            }
        }
        for(auto &x:p)
        {
            if(x.first==x.second)
            {
                ans.push_back(to_string(x.first));
            }
            else
            {
                string k=to_string(x.first)+"->"+to_string(x.second);
                ans.push_back(k);
            }
        }
        return ans;
    }
};