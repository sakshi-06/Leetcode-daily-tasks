class Solution {
public:
    bool isSubsequence(string s, string t) {
        unordered_map<char,vector<int>> mp;
        int curr_pos=-1;
        for(int i=0;i<t.size();i++)
        {
            mp[t[i]].push_back(i);
        }
        for(int i=0;i<s.size();i++)
        {
            if(mp.find(s[i])==mp.end()) return false;
            int x=upper_bound(mp[s[i]].begin(),mp[s[i]].end(),curr_pos)-mp[s[i]].begin();
            if(x==mp[s[i]].size()) return false;
            curr_pos=mp[s[i]][x];
        }
        return true;
    }
};