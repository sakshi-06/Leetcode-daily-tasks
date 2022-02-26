class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        int n=s.size();
        int row=0;
        int dir=0;
        vector<pair<int,int>> all;
        for(int i=0;i<n;i++)
        {
            all.push_back({row,i});
            if(dir==0)
            {
                row++;
                if(row==numRows)
                {
                    row=numRows-2;
                    dir=1;
                }
            }
            else
            {
                row--;
                if(row==-1)
                {
                    row=1;
                    dir=0;
                }
            }
        }
        sort(all.begin(),all.end());
        string ans="";
        for(auto &x:all)
        {
            ans+=s[x.second];
        }
        return ans;
    }
};