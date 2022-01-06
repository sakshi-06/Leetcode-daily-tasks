class Solution {
public:

    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> mp;
        for(auto &t:trips)
        {
            mp[t[1]]+=t[0]; //adding the curr passangers at the time
            mp[t[2]]-=t[0];  // removing the passangers if ther end point is reached
        }
        for(auto &x:mp)
        {
            if((capacity -= x.second)<0) return false; // at any time we have more passangers than capacity
        }
        return true;
    }
};