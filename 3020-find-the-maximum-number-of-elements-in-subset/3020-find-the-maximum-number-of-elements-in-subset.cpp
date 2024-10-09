class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,long long>hmap;
        for(int i=0;i<nums.size();i++){
            hmap[nums[i]]++;
        }
        long long maxv=INT_MIN;
        for(auto it:hmap){
            long long count=0;
            if(it.second>=2 && it.first!=1){
                long long temp=it.first*it.first;
                while(hmap.find(temp)!=hmap.end()){
                    count++;
                    if(hmap[temp]<2)break;
                    temp=temp*temp;
                }
                maxv=max(count,maxv);
            }
            if(it.first==1){
                count=(it.second-1)/2;
                maxv=max(count,maxv);
            }
        }
        long long ans=maxv*2+1;
        return ans;
    }
};