class Solution {
public:
    bool ispal(string &s)
    {
        int i=0,j=s.length()-1;
        while(i<=j)
        {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(string s, vector<vector<string>> &ans, vector<string> &v)
    {
        if(s.length()==0) 
        {
            ans.push_back(v);
            return;
        }
        for(int i=0;i<s.length();i++)
        {
            string left=s.substr(0,i+1);
            if(ispal(left))
            {
                v.push_back(left);
                solve(s.substr(i+1),ans,v);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        solve(s, ans,v);
        return ans;
    }
};