class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> mp;
        for(auto &x:s)
        {
            mp[x]++;
        }
        for(auto &x:t)
        {
            if(!mp.count(x))
            {
                return x;
            }
            else
            {
                mp[x]--;
                if(mp[x]==0) mp.erase(x);
            }
        }
       return 'x'; 
    }
};