class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int sign=1;
        long long int num=0;
        while(i<s.size() )
        {
            if(s[i]==' ') i++;
            else break;
        }
        if(s[i]=='-' || s[i]=='+')
        {
            s[i++]=='+'?sign=1:sign=-1;
        }
         while(i<s.size() && isdigit(s[i]))
        {
            num=num*10+(s[i++]-'0');
            if(num*sign >= INT_MAX) return INT_MAX;
            if(num*sign <= INT_MIN) return INT_MIN;
        }
        return num=num*sign;
    }
};