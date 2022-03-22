// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        //reverse(S.begin(),S.end());
        vector<string> temp;
        string str="";
        string ans="";
        for(int i=0;i<S.size();i++)
        {
            if(S[i]=='.')
            {
                reverse(str.begin(),str.end());
                temp.push_back(str);
                str="";
                
            }
            else str+=S[i];
        }
        reverse(str.begin(),str.end());
        temp.push_back(str);
        for(int i=0;i<temp.size()-1;i++)
        {
            ans+=temp[i];
            ans+=".";
        }
        ans+=temp[temp.size()-1];
        reverse(ans.begin(),ans.end());
        return ans;
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends