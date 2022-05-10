class Solution {
public:
    void sum(int k,int n, vector<vector<int>> &ans, vector<int> &v, int pos)
    {
        if(v.size()==k && n==0) return ans.push_back(v);
        for(int i=pos;i<=9;i++)
        {
            if(n-i>=0 && i>0)
            {
            v.push_back(i);
            int temp=i;
            //i=-i;
            sum(k,n-i,ans,v,i+1);
            //i=-i;
            v.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
       vector<vector<int>> ans;
        vector<int> v;
        sum(k, n, ans, v, 1);
        return ans;
    }
};