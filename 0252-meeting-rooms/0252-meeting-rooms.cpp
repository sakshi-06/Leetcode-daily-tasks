class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.empty()) return true;
        sort(intervals.begin(), intervals.end());
        int end = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<end) return false;
            else end = max(end, intervals[i][1]);
        }
        return true;
    }
};