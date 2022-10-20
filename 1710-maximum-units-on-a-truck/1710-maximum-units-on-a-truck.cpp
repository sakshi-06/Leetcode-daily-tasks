class Solution {
public:
    static bool cmp(vector<int>&a, vector<int> &b)
    {
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int ans=0;
        int i=0;
        while(i<boxTypes.size() && truckSize>0)
        {
            ans+=min(truckSize, boxTypes[i][0])*boxTypes[i][1];
            truckSize-=boxTypes[i][0];
            i++;
        }
        return ans;
    }
};