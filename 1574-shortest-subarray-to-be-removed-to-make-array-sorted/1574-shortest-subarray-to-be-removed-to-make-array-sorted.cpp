class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int i = 0;
        int j = arr.size() - 1;
        int n = arr.size();
        
        while (i < j && arr[i] <= arr[i+1]) i++;
        if (i + 1 == n) return 0; // Always increasing array
        while( j > i && arr[j] >= arr[j-1]) j--;
        
        int left = 0;
        int right = j;
        int ret = min(n-1-i, j);
        while(left <= i && right < n){
            if(arr[left] <= arr[right]){
                ret = min(ret, right-left-1);
                left++;
            }
            else right++;
        }
        return ret;       
    }
};