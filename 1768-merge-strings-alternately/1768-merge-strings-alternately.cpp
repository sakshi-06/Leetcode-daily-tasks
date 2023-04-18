class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int p1=0, p2=0;
        int n=word1.size();
        int m=word2.size();
        string word;
        bool first=true;
        while(p1<n && p2<m)
        {
            if(first)
            {
                word.push_back(word1[p1]);
                first= false;
                p1++;
            }
            else
            {
                word.push_back(word2[p2]);
                first=true;
                p2++;
            }
        }
        while(p1<n)
        {
            word.push_back(word1[p1++]);
        }
         while(p2<m)
        {
            word.push_back(word2[p2++]);
        }
        return word;
    }
};