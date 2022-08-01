class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int> &temp, int target,vector<int> &cand,int pos)
    {
        if(target ==0)
        {
            ans.push_back(temp);
            return;
        }
        // if(target<0 || pos<=0) return;
        for(int i=pos;i<cand.size();i++)
        {
            if(cand[i]<=target)
            {
                temp.push_back(cand[i]);
                solve(temp,target-cand[i],cand,i);
                temp.pop_back();
            }
            
        }
        return ;
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        solve(temp,target,candidates,0);
        return ans;
    }
};