class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        stringstream ss(s);
        string temp;
        while(ss>> temp)
        {
            reverse(temp.begin(), temp.end());
            ans+=temp;
            ans+=" ";
        }
        ans.pop_back();
        return ans;
    }
};