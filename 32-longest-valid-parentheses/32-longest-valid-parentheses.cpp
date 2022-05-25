class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size()==0) return 0;
        stack<int> st;
        st.push(-1);
        int res=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(') st.push(i);
            else
            {
                if(!st.empty()) st.pop();
                if(!st.empty()) res=max(res,i-st.top());
                else st.push(i);
            }
        }
        return res;
    }
};