class Solution {
public:
    int count(int n)
    {
        int cnt=0;
        while(n)
        {
            cnt+= n&1;
            n>>=1;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        if(n==0) return {0};
        vector<int> ans(n+1);
        ans[0]=0;
        ans[1]=1;
        int cnt=1;
        int i=2;
        while(i<=n)
        {
            ans[i]=count(i);
            i++;
        }
        return ans;
    }
};