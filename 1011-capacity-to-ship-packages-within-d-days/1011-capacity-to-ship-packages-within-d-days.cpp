class Solution {
public:
    bool check(vector<int> &w, int x, int days)
    {
        int d=1;
        int sum=0;
        for(int i=0;i<w.size()&&d<=days;i++)
        {
            if(sum+w[i]>x)
            {
                d++;
                sum=w[i];
            }
            else
            {
                sum+=w[i];
            }
        }
        return d<=days;
        
    }
    int shipWithinDays(vector<int>& weights, int days) {
       int sum=0;
        for(auto &x:weights)
        {
            sum+=x;
        }
        int l=*max_element(weights.begin(), weights.end());
        int r=sum;
        int ans=sum;
        if(days>=weights.size()) return *max_element(weights.begin(), weights.end());
        while(l<r)
        {
            int mid=l+(r-l)/2;
            if(check(weights,mid,days))
            {
                ans=mid;
                r=mid;
            }
            else l=mid+1;
        }
        return ans; 
    }
};