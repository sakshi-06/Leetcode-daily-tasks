class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        int j=0;
        for(int i=0;i<s.size();i++)
        {
            j=i;
            while(j<s.size() && s[i]==s[j])
            {
                j++;
            }
            int len=j-i;
            if(len>=3) ans.push_back({i,j-1});
            i=j-1;
        }
        return ans;
    }
};