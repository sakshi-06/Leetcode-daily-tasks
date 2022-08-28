class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        double time=0;
        vector<double> m;
        for(int i=0;i<dist.size();i++)
        {
            m.push_back(dist[i]/(double)speed[i]);
        }
        sort(m.begin(),m.end());
        int ans=0;
        for(int i=0;i<m.size();i++)
        {
            if(m[i]<=time)
            {
                return ans;
            }
            else 
            {
                time++;
                ans++;
            }
        }
        return ans;
    }
};