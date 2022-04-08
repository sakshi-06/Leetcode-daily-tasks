class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int ans=0;
    KthLargest(int k, vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
        }
        ans=k;
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size()>ans)
        {
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */