class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n=arr.size();
        vector<int> hi(n,0);
        vector<int> lo(n,0);
        map<int,int> mp;
        int res=1;
        mp[arr[n-1]]=n-1;
        hi[n-1]=1;
        lo[n-1]=1;
        for(int i=n-2;i>=0;i--)
        {
            auto l=mp.upper_bound(arr[i]);
            auto  h=mp.lower_bound(arr[i]);
            if (h != mp.end()) hi[i] = lo[h->second];
            if (l != mp.begin()) lo[i] = hi[(--l)->second];
            if (hi[i]) res++;
            mp[arr[i]] = i;
        }
        return res;
    }
};