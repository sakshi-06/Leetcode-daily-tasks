class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }

        if (s == goal) {
            vector<int> frequency(26, 0);
            for (auto& ch : s) {
                frequency[ch - 'a'] += 1;
                if (frequency[ch - 'a'] == 2) {
                    return true;
                }
            }
            return false;
        }
        
        int firstIndex = -1;
        int secondIndex = -1;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != goal[i]) {
                if (firstIndex == -1) {
                    firstIndex = i;
                } else if (secondIndex == -1) {
                    secondIndex = i;
                } else {
                    return false;
                }
            }
        }

        if (secondIndex == -1) {
            return false;
        }
        
        return s[firstIndex] == goal[secondIndex] && 
               s[secondIndex] == goal[firstIndex];
    }
};