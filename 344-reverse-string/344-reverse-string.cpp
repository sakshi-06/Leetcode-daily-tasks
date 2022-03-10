class Solution {
public:
    void reverseString(vector<char>& s) {
      int r=0,l=s.size()-1;
        while(r<l)
        {
            char temp=s[l];
            s[l--]=s[r];
            s[r++]=temp;
        }
    }
};