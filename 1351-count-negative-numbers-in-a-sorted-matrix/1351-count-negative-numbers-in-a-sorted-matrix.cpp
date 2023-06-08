class Solution {
public:
    int b_search(int l,int r,vector<int> &row)
    {
        int ans=-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(row[mid]<0)
            {
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
            
    }
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int cnt=b_search(0,m-1,grid[i]);
            if(cnt!=-1)
            {
                ans+=(m-cnt);
            }
        }
        return ans;
    }
};