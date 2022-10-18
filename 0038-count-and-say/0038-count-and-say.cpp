class Solution {
public:
    string countAndSay(int n) {
       string result ="1";
        for(int j=2;j<=n;j++)
        {
            string s=result;
            int first=0;
            result="";
            for(int i=1;i<=s.size();i++)
            {
                if(s[i]!=s[first])
                {
                    result+=to_string(i-first);
                    result+=s[first];
                    first=i;
                }
            }
        }
        return result;
    }
};