class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        vector<int> temp;
        for(auto& x:arr)
        {
            mp[x]++;
        }
        for(auto &x:mp)
        {
            temp.push_back(x.second);
        }
        sort(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++)
        {
            if(k<temp[i]) return temp.size()-i;
            k-=temp[i];
        }
       return 0;
    }
};