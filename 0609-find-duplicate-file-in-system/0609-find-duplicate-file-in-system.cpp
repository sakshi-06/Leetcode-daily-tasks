class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>> M;
        for(int i=0;i<paths.size();i++){
            string info = paths[i];
            stringstream ss(info);
            string s, directoryName;
            bool firstWord = true;
           while (getline(ss, s, ' ')) {
                if (firstWord) {
                    directoryName = s;
                    firstWord = false;
                } else {
                    // Find the file name
                    int fileNameLength = 0, i = 0;
                    while(i < s.length() && s[i++] != '(') fileNameLength++;
                    string fileName = s.substr(0, fileNameLength);

                    // Find the file content
                    int fileLength = 0, j = fileNameLength + 1;
                    while (j < s.length() && s[j++] != ')') fileLength++;
                    string fileContent = s.substr(fileNameLength + 1, fileLength);

                    M[fileContent].push_back(directoryName + "/" + fileName);
                }
            }
        }
        
        vector<vector<string>> ans;
        for (auto &[content, directoryAndFile] : M) {
            if(directoryAndFile.size() == 1) continue;
            ans.push_back(directoryAndFile);
        }
        
        return ans;
    }
};