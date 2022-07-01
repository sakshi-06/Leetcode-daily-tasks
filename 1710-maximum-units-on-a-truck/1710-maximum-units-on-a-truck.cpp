class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& box, int truck) {
        sort(box.begin(), box.end(),cmp);
        int i=0;
        int ans=0;
        //for(auto x:box) cout<< x[0]<<" "<<x[1]<<endl;
        while(truck>0 && i<box.size())
        {
            ans+=min(truck,box[i][0])*box[i][1];
            truck-=box[i][0];
            //cout<<truck<<" ";
            i++;
        }
        return ans;
        
    }
};