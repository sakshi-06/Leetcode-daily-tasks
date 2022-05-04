class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
       unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int ans=0;
        for(auto &it:mp)
        {
            int num = it.first, count = it.second;
        if(k - num == num) ans += count/2;   
        else if(mp.count(k - num)){  
          int Min = min(count, mp[k-num]);
          ans += Min;
          mp[num] -= Min;
          mp[k-num] -= Min;
        }
            
        }
        return ans;
    }
};