class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int n= points.size();
        if(n==0 || n==1) return n;
        int cnt=1;
        int end=points[0][1];
        for(auto &p:points)
        {
            if(p[0]<=end)
            {
                end=min(p[1],end);
            }
            else
            {
                cnt++;
                end=p[1];
            }
        }
        return cnt;
    }
};