class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& v) {
        int i = 0, j = v.size() - 1, len = v.size();
        if (len < 2) return v;
        while (true) {
            // moving to the first odd number with i
            while (i < len && !(v[i] % 2)) i++;
            // moving to the first even number with j
            while (j && v[j] % 2) j--;
			// checking if we are still in a valid scenario, otherwise we exit
            if (i >= j) break;
			// if so, we swap and update i and j
            swap(v[i++], v[j--]);
        }
        return v;
    }
};