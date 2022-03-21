class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> last_pos;
        for(int i=0;i<s.size();i++)
        {
            last_pos[s[i]]=i;
        }
        int i=0,end=-1,start=0;
        vector<int> ans;
        while(i<s.size())
        {
            end=max(end,last_pos[s[i]]);
            if(end==i)
            {
                ans.push_back(end-start+1);
                start=end+1;
                end=-1;
            }
            i++;
            
        }
        return ans;
    }
};