class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int i=0,j=0,index=0;
        while(i<n)
        {
            j=i;
            while(j<n && chars[i]==chars[j])
            {
                j++;
            }
            chars[index]=chars[i];
            index++;
            if(j-i>1)
            {
                for(auto x:to_string(j-i))
                {
                    chars[index++]=x;
                }
            }
            i=j;
        }
        return index;
    }
};