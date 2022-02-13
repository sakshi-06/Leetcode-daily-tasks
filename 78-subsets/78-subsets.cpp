class Solution {
public:
    void dfs(vector<int>& nums,vector<vector<int>>& v,int start,int N,vector<int>& vec){
    if(start==N){
            v.push_back(vec);
            return;
        }
        for(int i=start;i<N;i++){
            vec.push_back(nums[i]);
            dfs(nums,v,i+1,N,vec);
            vec.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int N=nums.size();
        vector<vector<int>> v;
        vector<int> vec;
        int start=0;
        for(int i=0;i<N+1;i++){
            dfs(nums,v,start,i,vec);
        }
        return v;
    }
};