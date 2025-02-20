class Solution {
    bool solve(int i, int j, string &s, vector<vector<int>>& dp) {
        if (i >= j) return true;  // Base case: single character or empty substring is always a palindrome

        if (dp[i][j] != -1) return dp[i][j]; // If already computed, return memoized result

        if (s[i] == s[j]) {
            dp[i][j] = solve(i + 1, j - 1, s, dp);
        } else {
            dp[i][j] = false;
        }
        
        return dp[i][j];
    }

public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxLen = 0;  // Fix: Initialize to 0 instead of -1
        int sp = 0;
        vector<vector<int>> dp(n, vector<int>(n, -1)); // Corrected DP size
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {  // Fix: `j` should start from `i`
                if (solve(i, j, s, dp)) {
                    if (j - i + 1 > maxLen) {
                        maxLen = j - i + 1;
                        sp = i;
                    }
                }
            }
        }
        
        return s.substr(sp, maxLen); // Extract longest palindromic substring
    }
};