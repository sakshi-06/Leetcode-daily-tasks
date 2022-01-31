class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
      
        int start=0,end=0,sum=0;
        while(end<s.length())
        {
            sum+=abs(s[end]-t[end++]);
            if(sum>maxCost)
                sum-=abs(s[start]-t[start++]);
        }
        return end-start;
    }
};