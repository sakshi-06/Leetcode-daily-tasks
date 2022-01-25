class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int i=0;
        int n=arr.size();
        if(n<3)return false;
        while(i+1<n && arr[i+1]>arr[i])
        {
            i++;
        }
        if(i==0 || i==n-1) return false;
        //i++;
        while(i+1< n && arr[i+1]<arr[i])
        {
            i++;
        }
        return i==n-1;
    }
};