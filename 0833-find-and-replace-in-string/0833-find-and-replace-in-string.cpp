class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        unordered_map<int, vector<string>> mp;
        for(int i = 0;i < indices.size();i++){
            mp[indices[i]].push_back(sources[i]);
            mp[indices[i]].push_back(targets[i]);
        }   

        string ans;
        for(int i = 0;i < s.length();i++){
            if(mp.count(i)){
                int flag = 0;
                for(int j = 0;j < mp[i].size();j += 2){
                    if(mp[i][j] == s.substr(i, mp[i][j].length())){
                        ans += mp[i][j + 1];
                        i += mp[i][j].length() - 1;
                        flag = 1;
                        break;
                    }
                }
                if(!flag) ans += s[i];
            }
            else ans += s[i];
        }
        
        return ans;
    }
};