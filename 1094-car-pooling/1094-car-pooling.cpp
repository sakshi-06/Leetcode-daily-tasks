class Solution {
public:

    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int passengers[1001]={0};
        for(auto &t:trips)
        {
            for(int i=t[1];i<t[2];i++)
            {
                passengers[i]+=t[0];
                if(passengers[i]>capacity) return false;
            }
        }
        return true;
    }
};