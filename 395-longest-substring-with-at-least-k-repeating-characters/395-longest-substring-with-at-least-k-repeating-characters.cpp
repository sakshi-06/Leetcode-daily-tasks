class Solution {
public:
    int longestSubstring(string s, int k) {
        if(k>s.length())
        {
            //even if all character are same they can't have freq k
            //as k>length of array
            return 0;
        }
        return helper(s,0,s.length(),k);
    }
    int helper(string s,int start,int end,int k)
    {
        if(end-start<k)
            return  0;
        //we get the freq of the every charcter in s between start and end
        vector<int> freq(26,0);
        for(int i=start;i<end;i++)
        {
         freq[s[i]-'a']++;   
        }
        //get the substring again where freq of every character is greater than k
        for(int i=start;i<end;i++)
        {
            if(freq[s[i]-'a']<k)
            {
                //this cannot form result
                //now find the last index upto which we cannot make result
                int j=i+1;
                while(j<end && freq[s[j]-'a']<k)
                    j++;
                //cal the max substr from left and right
                return max(helper(s,start,i,k),helper(s,j,end,k));
            }
        }
        //if all character freq >=k 
        return end-start;
    }
};