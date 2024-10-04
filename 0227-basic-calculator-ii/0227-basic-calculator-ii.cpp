class Solution {
public:
    int calculate(string s) {
        int l = s.size();
        if(l==0) return 0;
        int currNumber =0, lastNumber =0, result =0;
        char sign = '+';
        for(int i=0;i<l;i++){
            char currChar = s[i];
            if(isdigit(currChar)){
                currNumber = (currNumber * 10) + (currChar - '0');
            }
            if(!isdigit(currChar) && !iswspace(currChar) || i == l-1){
                if(sign == '+' || sign == '-'){
                    result += lastNumber;
                    lastNumber = (sign == '+') ? currNumber : - currNumber;
                }
                else if(sign == '*'){
                    lastNumber = lastNumber * currNumber;
                } else if(sign =='/'){
                    lastNumber = lastNumber / currNumber;
                }
                sign = currChar;
                currNumber =0;
            }
        }
        result += lastNumber;
        return result;
    }
};