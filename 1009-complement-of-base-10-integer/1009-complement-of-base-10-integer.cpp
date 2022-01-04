class Solution {
public:
    int bitwiseComplement(int n) {
        int c=1;
        while(c<n)
        {
            c=(c<<1)|1;
        }
        return c^n;
    }
};