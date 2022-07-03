class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> st;
        for(auto &s:emails)
        {
            //stringstream ss(s,'@');
            string token="";
            bool plus=false;
            bool at=false;
            for(auto &ch:s)
            {
                if(ch=='@')
                {
                    at=true;
                }
                if(ch=='+')
                {
                    plus=true;
                }
                if(ch=='.' && (at==false)) continue;
                if(plus==true && (at==false)) continue;
                token.push_back(ch);
            }
            st.insert(token);
        }
        return st.size();
    }
};