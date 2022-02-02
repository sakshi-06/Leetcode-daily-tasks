class Solution {
public:
    bool check(string p,unordered_map<int,int> mp)
    {
        for(int i=0;i<p.size();i++)
        {
            mp[p[i]]--;
            if(mp[p[i]]<0) return false;
        }
        for(auto &x:mp)
        {
            if(x.second!=0) return false;
        }
        return true;
        
    }
    vector<int> findAnagrams(string s, string p) {
        map<int,int> mp1;
        map<int,int> mp2;
        for(auto&x:p)
        {
            mp2[x]++;
        }
        vector<int> ans;
        for(int i=0;i<p.size();i++)
        {
            mp1[s[i]]++;
        }
        if(mp1==mp2) ans.push_back(0);
        int j=0;
        for(int i=p.size();i<s.size();i++)
        {
            mp1[s[i]]++;
            while(mp1!=mp2 && i-j+1>p.size())
            {
                mp1[s[j]]--;
                if(mp1[s[j]]==0) mp1.erase(s[j]);
                j++;
                if(mp1==mp2) ans.push_back(j);
            }
            
        }
        return ans;
    }
};