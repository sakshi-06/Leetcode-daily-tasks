class Solution {
public:
    bool detectCapitalUse(string word) {
       if(isupper(word[0]))
       {
           int cnt=1;
           for(int i=1;i<word.size();i++)
           {
               if(isupper(word[i])) cnt++;
           }
           if(cnt==1 || cnt==word.size()) return true;
           return false;
       }
        else
        {
            for(int i=0;i<word.size();i++)
            {
                if(isupper(word[i])) return false;
            }
            return true;
        }
    }
};