class Solution {
public:
    int res=0;
    int seen=0;
    int countArrangement(int n,int pos=1) {
        
        int bit=0;
        if(pos>n)res++;
        for(int i=1;i<=n;i++)
        {
            bit=1<<i;
            if(!(seen& bit) && (i%pos==0 || pos%i==0))
            {
                seen^=bit;
                countArrangement(n,pos+1);
                seen^=bit;
            }
        }
        return res;
    }
};