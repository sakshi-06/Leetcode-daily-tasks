class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
      });
      // dp keeps some of the visited element in a sorted list, and its size is length Of LIS sofar.
      // It always keeps the our best chance to build a LIS in the future.
      vector<int> dp;
      for (auto envelope: envelopes) {
        auto it = lower_bound(dp.begin(), dp.end(), envelope[1]);
        if (it == dp.end()){
          // If envelope[1] is the biggest, we should add it into the end of dp.
          dp.push_back(envelope[1]);
        } else {
          // If envelope[1] is not the biggest, we should keep it in dp and replace the previous
          // envelope[1] in this position. Because even if envelope[1] can't build longer LIS
          // directly, it can help build a smaller dp, and we will have the best chance to build
          // a LIS in the future. All elements before this position will be the best(smallest) LIS
          // sor far.
          *it = envelope[1];
        }
      }
      // dp doesn't keep LIS, and only keep the length Of LIS.
      return dp.size();
    }
};