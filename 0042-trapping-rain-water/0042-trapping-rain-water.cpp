class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left_max=0, right_max=0;
        int left=0, right=n-1;
        int ans=0;
        while(right>left){
            if(height[left] > left_max) left_max = height[left];
            if(height[right] > right_max) right_max = height[right];
            if(left_max < right_max){
                ans+= max(0, left_max-height[left]);
                left++;
            }
            else{
                ans+=max(0, right_max-height[right]);
                right--;
            }
        }
        return ans;
    }
};