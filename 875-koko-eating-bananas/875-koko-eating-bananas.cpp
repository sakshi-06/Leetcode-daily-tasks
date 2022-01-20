class Solution {
public:
    bool check(vector<int>&piles,int h,int k)
    {
        int ans=0;
        for(int i=0;i<piles.size();i++)
        {
            ans+=piles[i]/k;
            if(piles[i]%k) ans++;
            if(ans>h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,r=*max_element(piles.begin(),piles.end());
        int ans=0;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(check(piles,h,mid))
            {
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};