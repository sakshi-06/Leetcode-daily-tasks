class Solution {
public:
    int i=0;
    int scoreOfParentheses(string s) {
        int score=0;
        while(i<s.size())
        {
            char first=s[i];
            i++;
            if(first=='(')
            {
                if(s[i]==')')
                {
                    i++;
                    score++;
                    //return score;
                }
                else
                {
                    //i++;
                    score+=2*(scoreOfParentheses(s));
                    //return score;
                }
            }
            else
            {
                return score;
            }
        }
        return score;
    }
};