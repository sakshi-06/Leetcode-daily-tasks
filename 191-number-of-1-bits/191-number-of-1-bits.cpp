class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {
            // updating res
			res += n & 1;
			// reducing n
            n >>= 1;
        }
        return res;
    }
};