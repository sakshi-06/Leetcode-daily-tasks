class Solution {
public:
    long long int ans=0;
    void mergesort(int l,int r,int mid,vector<int> &nums)
    {
        int n=mid-l+1;
        int m=r-mid;
        vector<int> v1(n);
        vector<int> v2(m);
        for(int i=0;i<n;i++)
        {
            v1[i]=nums[l+i];
        }
        for(int i=0;i<m;i++)
        {
            v2[i]=nums[mid+i+1];
        }
        int i=0,j=0,k=l;
       // int ans=0
        while(i<n && j<m)
        {
            if(v1[i]>(long)2*v2[j])
            {
                ans+=(n-i);
                j++;
            }
            else
            {
                i++;
            }
        }
        i=0;
        j=0;
        while(i < n && j < m){
            if(v1[i] < v2[j]){
                nums[k++] = v1[i++];
            }else{
                nums[k++] = v2[j++];
            }
        }
        while(i < n)
            nums[k++] = v1[i++];
        while(j < m)
            nums[k++] = v2[j++];
        
    }
    void merge(int l,int r,vector<int> &nums)
    {
        if(l>=r) return ;
        int mid=l+(r-l)/2;
        merge(l,mid,nums);
        merge(mid+1,r,nums);
        mergesort(l,r,mid,nums);
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        merge(0,n-1,nums);
        return ans;
    }
};