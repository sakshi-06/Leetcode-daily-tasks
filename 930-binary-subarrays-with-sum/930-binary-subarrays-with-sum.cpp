class Solution {
int atMost(vector<int> A, int goal) {
        int N = A.size(), i = 0, j = 0, cnt = 0, ans = 0;
        while (j < N) {
            cnt += A[j++];
            while (i < j && cnt > goal) cnt -= A[i++];
            ans += j - i;
        }
        return ans;
    }
public:
    int numSubarraysWithSum(vector<int>& A, int goal) {
        return atMost(A, goal) - atMost(A, goal - 1);
    }
};