class Solution {
public:
    bool isValid(string st) {
        stack<char> s;
        for(auto i:st)
        {
             if(i == '(')
            s.push(')');
        else if(i == '{')
            s.push('}');
        else if(i == '[')
            s.push(']');
        else if( s.empty() || s.top() != i)
            return false;
        else if(s.top() == i)
            s.pop();
        }
        return s.empty();
    }
};