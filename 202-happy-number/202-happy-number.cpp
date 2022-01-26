class Solution {
public:
    int next(int n)
    {
        int total_sum=0;
        while(n>0)
        {
            int d=n%10;
            n=n/10;
            total_sum+= d*d;
        }
        return total_sum;
    }
    bool isHappy(int n) {
        int slow=n;
        int fast=next(n);
        while(fast!=1 && slow!=fast)
        {
            slow=next(slow);
            fast=next(next(fast));
        }
        return fast==1;
    }
};