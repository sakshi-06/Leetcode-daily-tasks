class Solution {
public:
    string formString(int maxWidth, vector<string>& line, int totalWordsLen){
        int spacesLeft = maxWidth - totalWordsLen;
        for(int i=0;i<spacesLeft;i++){
            if(line.size()==1) line[0]+=" ";
            else{
                line[i%(line.size()-1)]+= " ";
            }
        }
        string finalString = accumulate(line.begin(), line.end(), string(""));
        return finalString;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        vector<string> line;
        int totalWordsLen=0;
        for(string &word:words){
            int len = word.size();
            int spaces = line.size();
            if(len+spaces+totalWordsLen > maxWidth){
                ans.push_back(formString(maxWidth, line, totalWordsLen));
                line.clear();
                totalWordsLen = 0;
            }
            totalWordsLen+= len;
            line.push_back(word);
        }
        string fnl;
        for(int i=0;i<line.size();i++){
          fnl+= (line[i]+" ");  
        }
        fnl.pop_back();
       for(int i = fnl.length();i<maxWidth;i++)
            fnl+=" "; 
        ans.push_back(fnl);
        return ans;
    }
};