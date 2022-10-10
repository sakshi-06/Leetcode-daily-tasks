class Solution {
public:
    string breakPalindrome(string p) {
        if(p.size()==1) return "";
         int n=p.size();
        for(int i=0;i<n/2;i++)
        {
            if(p[i]!='a')
            {
                p[i]='a';
                return p;
            } 
        }
        p[n-1]='b';  // agar har place mei a hai, to last char ko b kardo
        return p;
    }
};