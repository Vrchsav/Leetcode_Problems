class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true; // Already equal

        vector<int> diff;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                diff.push_back(i);
            }
        }

        // If more than 2 mismatches, swapping one pair can't fix it
        if (diff.size() != 2) return false;

        // Check if swapping the two differing characters makes s1 equal to s2
        return (s1[diff[0]] == s2[diff[1]] && s1[diff[1]] == s2[diff[0]]);
    }
};
