class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string>ans;
        sort(folder.begin(), folder.end());
        ans.push_back(folder[0]);
        for(int i=1;i<folder.size();i++){
            string last_folder = ans.back();
            last_folder.push_back('/');
            if(folder[i].substr(0,last_folder.size())==last_folder){
                continue;
            }
                ans.push_back(folder[i]);
            
        }
        return ans;
    }
};