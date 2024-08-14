class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> visited(128, -1); // Initialize the visited array for ASCII characters.

        int ans = 0; // The final answer, which will store the length of the longest substring.
        int start = 0; // Start index of the current substring without repeating characters.

        for (int i = 0; i < s.size(); i++) {
            if (visited[s[i]] != -1 && visited[s[i]] >= start) {
                // If the character is repeated within the current substring,
                // update the start index to just after the last occurrence of this character.
                start = visited[s[i]] + 1;
            }
            // Update the most recent index where this character was seen.
            visited[s[i]] = i;
            // Update the answer if the current substring is longer.
            ans = max(ans, i - start + 1);
        }

        return ans;
    }
};
