class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num=="0" || k==num.size()) return "0";
        string ans="";
        int n=num.size();
        for(int i=0;i<n;i++)
        {
            while(!ans.empty() && ans.back()-'0'>num[i]-'0' && k)
            {
                ans.pop_back();
                k--;
            }
            if(ans.length() || num[i]!='0') ans.push_back(num[i]);
        }
        while(ans.length() && k--)
        {
            ans.pop_back();
        }
        if(ans.empty()) return "0";
        return ans;
    }
};