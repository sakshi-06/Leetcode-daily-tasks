class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        //if we multiply all odd numbers by 2 it becomes even and then we only 
        //have to perform single operation
        // if we have even numbers it never increase, so we need to decrease the largest number until it's odd
        for(auto &x:nums)
        {
            if(x%2==1)
            {
                x=x*2;
            }
        }
        set<int> s(nums.begin(),nums.end());
        int res=*s.rbegin()-*s.begin();
        while (*s.rbegin() % 2 == 0) {
            s.insert(*s.rbegin() / 2);
            s.erase(*s.rbegin());
            res = min(res, *s.rbegin() - *s.begin());
        }
        return res;
    }
};