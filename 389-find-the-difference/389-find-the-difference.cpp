class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int i=0;
        int j=0;
        while(i<s.size())
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else
            {
                return t[j];
                j++;
                
            }
        }
        return t.back();
    }
};