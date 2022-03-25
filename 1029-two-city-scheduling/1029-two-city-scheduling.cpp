class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
       int n=costs.size();
        vector<int> loss(n, 0);
        int tot=0;
        for(int i=0;i<costs.size();i++)
        {
            tot+=costs[i][0];
            loss[i]=costs[i][0]-costs[i][1];
        }
        sort(loss.begin(), loss.end(), greater<int>());
        for(int i=0;i<n/2;i++)
        {
            tot-=loss[i];
        }
        return tot;
    }
};