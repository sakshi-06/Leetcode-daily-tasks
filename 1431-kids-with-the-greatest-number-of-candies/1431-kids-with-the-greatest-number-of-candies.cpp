class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
         int max_val = *max_element(candies.begin(), candies.end());
        vector<bool> ans(candies.size());
        for(int i=0;i<candies.size();i++)
        {
            if(extraCandies+candies[i]>=max_val)ans[i]=true;
            else ans[i]=false;
        }
        return ans;
    }
};