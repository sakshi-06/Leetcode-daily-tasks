class Solution {
public:
    bool solve(vector<int> &piles, int x, int h)
    {
        int time=0;
        for(auto p:piles)
        {
            if(p<x) time++;
            else
            {
                time+=ceil((double)p/(double)x);
            }
        }
        if(time<=h) return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int l=1, r=*max_element(piles.begin(), piles.end());
        int ans=r;
        while(l<r)
        {
            int mid=l+(r-l)/2;
            if(solve(piles,mid,h)==true)
            {
                
                r=mid;
            }
            else l=mid+1;
        }
        return l;
    }
};