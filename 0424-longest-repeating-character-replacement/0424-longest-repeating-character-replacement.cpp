class Solution {
public:
    int characterReplacement(string s, int k) {
       unordered_map<char,int> mp;
        int max_letters=0;
        int ans=0;
        int j=0;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
            max_letters=max(max_letters,mp[s[i]]);
            if(i-j+1-max_letters>k)
            {
                mp[s[j]]--;
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};