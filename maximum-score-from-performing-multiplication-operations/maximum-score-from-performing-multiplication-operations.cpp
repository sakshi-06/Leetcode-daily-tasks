class Solution {
public:
    int dp[1001][1001] = {};
int dfs(vector<int>& nums, vector<int>& mults, int l, int i) {
    if (i >= mults.size())
        return 0;
    if (!dp[l][i]) {
        int r = nums.size() - 1 - (i - l);
        dp[l][i] = max(nums[l] * mults[i] + dfs(nums, mults, l + 1, i + 1), 
            nums[r] * mults[i] + dfs(nums, mults, l, i + 1));
    }
    return dp[l][i];
}
int maximumScore(vector<int>& nums, vector<int>& mults) {
    return dfs(nums, mults, 0, 0);
}
};