class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int> &c,int t,vector<int> &temp,int pos)
    {
        if(t==0)
        {
            ans.push_back(temp);
            return ;
        }
        for(int i=pos;i<c.size();i++)
        {
            if(t-c[i]>=0)
            {
                temp.push_back(c[i]);
                solve(c,t-c[i],temp,i);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        solve(candidates,target,temp,0);
        return ans;
    }
};