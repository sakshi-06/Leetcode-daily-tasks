class Solution {
public:
    bool isVowel(char s)
    {
        if(s=='a'||s=='e'||s=='i'||s=='o'||s=='u')
        {
            return true;
        }
        else return false;
    }
    int maxVowels(string s, int k) {
        int cnt=0;
        for(int i=0;i<k;i++)
        {
            if(isVowel(s[i]))
            {
                cnt++;
            }
        }
        int ans=cnt;
        for(int i=k;i<s.size();i++)
        {
            if(isVowel(s[i-k]))
            {
                cnt--;
            }
            if(isVowel(s[i])){
                cnt++;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};