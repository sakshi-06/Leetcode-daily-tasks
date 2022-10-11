class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int one=INT_MAX,two=INT_MAX;
        for(auto num:nums)
        {
            if(num<one) one=num;
            else if(one<num && num<two) two=num;
            else if(num>two) return true;
        }
        return false;
    }
};