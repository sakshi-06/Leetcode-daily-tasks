class Solution {
public:
    unordered_map<int,string> mp;
    vector<string> res;
    void solve(string &d,string ans,int pos)
    {
        if(pos==d.size())
        {
            res.push_back(ans);
            return ;
        }
        int j=d[pos]-'0';
        for(int i=0;i<mp[j].size();i++)
        {
            ans.push_back(mp[j][i]);
            solve(d,ans,pos+1);
            ans.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        if(digits=="") return {};
        solve(digits,"",0);
        return res;
        
    }
};