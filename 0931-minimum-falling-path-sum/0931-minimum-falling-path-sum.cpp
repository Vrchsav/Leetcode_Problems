
class Solution {
    int solve(vector<vector<int>>& matrix, int row, int col) {
        // Create a DP table initialized with 0
        vector<vector<int>> dp(row, vector<int>(col, 0));

        // Initialize the first row of dp with the values of the first row of matrix
        for (int i = 0; i < col; i++) {
            dp[0][i] = matrix[0][i];
        }

        // Fill the DP table row by row
        for (int i = 1; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int up = matrix[i][j] + dp[i - 1][j];
                
                int left = INT_MAX;
                if (j > 0) {
                    left = matrix[i][j] + dp[i - 1][j - 1];
                }

                int right = INT_MAX;
                if (j < col - 1) {
                    right = matrix[i][j] + dp[i - 1][j + 1];
                }

                // Choose the minimum of the three directions
                dp[i][j] = min(up, min(left, right));
            }
        }

        // Find the minimum value in the last row of dp
        int ans = INT_MAX;
        for (int i = 0; i < col; i++) {
            ans = min(ans, dp[row - 1][i]);
        }
        return ans;
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        // Call solve function to get the result
        return solve(matrix, row, col);
    }
};