class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map < int , int > occupiedRooms;
        for(auto &a : intervals) {
            occupiedRooms[a[0]]++;
            occupiedRooms[a[1]]--;
        }
        int currentMeetings = 0 , roomsRequired = 0;
        for(auto &currentValue : occupiedRooms) {
            int time = currentValue.first, meetingsHere = currentValue.second;
            currentMeetings += meetingsHere;
            roomsRequired = max(roomsRequired, currentMeetings);
        }
        return roomsRequired;
    }
};