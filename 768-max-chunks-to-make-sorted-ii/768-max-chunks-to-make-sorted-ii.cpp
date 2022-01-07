class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
       stack<pair<int,int>>st;
        for(int i=0;i<arr.size();i++) {
            pair<int,int> it=make_pair(arr[i],arr[i]);
            while( (!st.empty()) && (st.top().first>it.second) ) {
                auto pre=st.top();
                st.pop();
                it.second = min(pre.second,it.second);
                it.first = max(pre.first, it.first);
            }
            st.push(it);
        }
        return st.size();
    }
};