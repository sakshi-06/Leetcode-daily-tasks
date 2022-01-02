class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> mp;
        int cnt=0;
        for(int i=0;i<time.size();i++)
        {
            int div=time[i]%60;
            int key=60-div;
            if(div==0)
            {
                cnt+=mp[0];
            }
            if(!mp.empty() && mp.find(key)!=mp.end())
            {
                cnt+=mp[key];
            }
            mp[div]++;
        }
        return cnt;
    }
};