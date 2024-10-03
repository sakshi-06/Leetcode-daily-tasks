class Solution {
public:
    string formString(vector<string> &line, int maxWidth, int &cnt){
        int spaces = maxWidth-cnt;
        for(int i=0;i<spaces;i++){
            if(line.size()==1){
                line[0]+=" ";
            } else{
                line[i%(line.size()-1)]+=" ";
            }
        }
        string finl = accumulate(line.begin(),line.end(),string(""));
        line.clear();
        cnt = 0;
        return finl;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        vector<string> line;
        int cnt=0;
        for(int i=0;i<words.size();i++){
            int l = words[i].size();
            if(l+line.size()+cnt > maxWidth){
                ans.push_back(formString(line,maxWidth, cnt));
            }
            line.push_back(words[i]);
            cnt+=l;
        }
        string finl;
        for(auto it : line)
            finl+=it+" ";
        finl.pop_back();
        for(int i = finl.length();i<maxWidth;i++)
            finl+=" ";
        ans.push_back(finl);
        return ans;
        
    }
};