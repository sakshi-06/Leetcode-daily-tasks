class Solution {
public:
    void solve(string &s, unordered_set<string> dict,int idx,vector<string> &ans, string curr)
    {
        if(idx==s.size())
        {
            curr.pop_back();
            ans.push_back(curr);
            return;
        }
        string temp="";
        for(int i=idx;i<s.size();i++)
        {
            temp.push_back(s[i]);
            if(dict.find(temp)!=dict.end())
            {
                solve(s,dict,i+1,ans,curr+temp+" ");
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        vector<string> ans;
        string curr="";
        solve(s,dict,0,ans,curr);
        return ans;
    }
};