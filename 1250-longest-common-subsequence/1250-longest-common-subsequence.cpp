class Solution {
    int solve(string text1, string text2, int n1, int n2) {
        // Initialize the DP table with zeros
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        // Fill the DP table
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                // Check if characters match
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] =
                        1 + dp[i - 1][j - 1]; // Include the matching character
                } else {
                    // Take the maximum from ignoring either character
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // The result is in dp[n1][n2], the last cell of the DP table
        return dp[n1][n2];
    }

public:
    int longestCommonSubsequence(string text1, string text2) {

        int n1 = text1.size();
        int n2 = text2.size();
        return solve(text1, text2, n1, n2);
    }
};