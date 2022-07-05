class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
       string ans="";
        int n=s.size();
        int K=k;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]!='-')
            {
                if(K==0)
                {
                    ans.push_back('-');
                    K=k;
                }
                ans.push_back(toupper(s[i]));
                K--;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};