class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        int ans=0;
        unordered_map<char,int> charCountMap;
        int start=0;
        for(int i=0;i<s.size();i++)
        {
            charCountMap[s[i]]++;
            while(charCountMap[s[i]]>1)
            {
                charCountMap[s[start]]--;
                if(charCountMap[s[start]]==0)
                {
                    charCountMap.erase(s[start]);
                }
                start++;
            }
            ans=max(ans, i-start+1);
        }
        return ans;
    }
};