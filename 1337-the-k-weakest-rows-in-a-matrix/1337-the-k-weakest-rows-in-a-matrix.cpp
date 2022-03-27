class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        //int count[mat.size()];
        vector<int> v;
        multimap<int, int> m;
        for(int i=0;i<mat.size();i++)
        {
            int cnt=0;
            for(int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j]==0) break;
                if(mat[i][j]==1) cnt++;
            }
            m.insert({cnt,i});
        }
        //sort(m.begin(), m.end());
        for(auto it = m.begin(); it != m.end(); ++it) {
            if(k == 0) break;
            v.push_back(it->second);
            k--;
        }
        return v;
    }
};