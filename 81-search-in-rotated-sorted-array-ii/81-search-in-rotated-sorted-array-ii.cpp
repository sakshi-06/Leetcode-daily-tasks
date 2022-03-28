class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 1) return (target == nums[0]);
        int max_num = n-1;
        for(int i = 1; i < n; ++i){
            if(nums[i] < nums[i-1]) max_num = i-1;
        }
        return (binarySearch(nums, 0, max_num, target) || binarySearch(nums, max_num + 1, n-1, target));
    }
    
private:
    int binarySearch(vector<int>& nums, int left, int right,int target) {
        int l = left, r = right;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(target == nums[mid]) return true;
            if(target > nums[mid]) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
};