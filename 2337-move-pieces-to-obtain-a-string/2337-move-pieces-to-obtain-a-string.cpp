class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int i = 0, j = 0;

        // Traverse both strings simultaneously
        while (i < n || j < n) {
            // Skip '_' in the `start` string
            while (i < n && start[i] == '_') i++;
            // Skip '_' in the `target` string
            while (j < n && target[j] == '_') j++;

            // If both strings are fully traversed, return true
            if (i == n && j == n) return true;

            // If one string finishes early or mismatched character
            if (i == n || j == n || start[i] != target[j]) return false;

            // If `L` in `start` is found after `target`, it's invalid
            if (start[i] == 'L' && i < j) return false;

            // If `R` in `start` is found before `target`, it's invalid
            if (start[i] == 'R' && i > j) return false;

            // Move to the next character
            i++;
            j++;
        }

        return true;
    }
};
