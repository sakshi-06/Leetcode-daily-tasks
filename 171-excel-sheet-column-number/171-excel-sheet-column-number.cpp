class Solution {
public:
    int titleToNumber(string c) {
        int ans=0;
        int n=c.size();
        for(int i=0;i<n;i++)
        {
            ans=(c[i]-'A'+1)+ans*26;
        }
        
        return ans;
    }
};
