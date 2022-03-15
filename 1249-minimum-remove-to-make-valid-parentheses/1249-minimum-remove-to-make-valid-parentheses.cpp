class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else if(!st.empty() && s[i]==')')
            {
                st.pop();
            }
            else if(s[i]==')')
            {
                s[i]='*';
            }
        }
        string ans="";
        //if(!st.empty()) cout<<st.top()<<" ";
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]=='*')
            {
                continue;
            }
            else if(!st.empty() && i==st.top())
            {
                st.pop();
                continue;
            }
            else
            {
                ans+=s[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};