class Solution {
public:
    static bool cmp(vector<int> &a,vector<int>&b)
    {
        if(a[0]==b[0])
        {
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(), cmp);
        int c=intervals[0][0],d=intervals[0][1];
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]>=ans.back()[0] && intervals[i][1]<=ans.back()[1])
            {
                // ans.pop_back();
                // ans.push_back(intervals[i]);
            }
            else
            {
                //ans.pop_back();
                ans.push_back(intervals[i]);
            }
        }
        return ans.size();
    }
};