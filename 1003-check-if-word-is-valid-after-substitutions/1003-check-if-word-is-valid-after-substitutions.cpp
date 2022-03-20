class Solution {
public:
    bool isValid(string s) {
      stack<char> st;
       for(auto &i:s)
       {
           if(i=='c')
           {
               if(st.empty() || st.top()!='b')
               {
                   return false;
               }
               if(!st.empty()) st.pop();
               if(st.empty() || st.top()!='a')
               {
                   return false;
               }
               if(!st.empty()) st.pop();
           }
           else
           {
               st.push(i);
           }
       }
        return st.empty();
    }
};