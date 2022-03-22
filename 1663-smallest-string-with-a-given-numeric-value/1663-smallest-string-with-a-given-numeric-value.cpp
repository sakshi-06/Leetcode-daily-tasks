class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans="";
        while(n>0)
        {
            if(k>26 && k-26>=n-1)
            {
                ans.push_back('z');
                k-=26;
                n--;
            }
            else
            {
                ans.push_back(char(96+(k-n+1)));
                k=n-1;
                n--;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};