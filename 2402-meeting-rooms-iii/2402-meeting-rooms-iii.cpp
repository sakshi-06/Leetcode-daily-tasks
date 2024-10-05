class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<long long int> room_count(n,0);
        priority_queue<vector<long long int>, vector<vector<long long int>>, greater<vector<long long int>>> used_rooms, unused_rooms;
        sort(meetings.begin(), meetings.end());
        int t=0;
        for(int i=0;i<n;i++) unused_rooms.push({i});
        for(auto x:meetings){
            int s=x[0], e=x[1];
            while(!used_rooms.empty() && used_rooms.top()[0]<=s){
                long long int r = used_rooms.top()[1];
                used_rooms.pop();
                unused_rooms.push({r});
            }
            if(unused_rooms.size() > 0){
                long long int r= unused_rooms.top()[0];
                unused_rooms.pop();
                room_count[r]++;
                used_rooms.push({e,r});
            }else{
                vector<long long int> topmost = used_rooms.top();
                used_rooms.pop();
                room_count[topmost[1]]++;
                long long int newEnd = topmost[0];
                newEnd += (e-s);
                used_rooms.push({newEnd, topmost[1]});
            }
        }
        long long int maxi=0;
        for(int i=0;i<n;i++){
            if(room_count[i]> room_count[maxi]) maxi=i;
        }
        return maxi;
    }
};