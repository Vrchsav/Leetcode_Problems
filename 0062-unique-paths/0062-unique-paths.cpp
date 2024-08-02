class Solution {
private:
    int solve(int m, int n, int i, int j, vector<vector<int>>& mpp) {
        // Base Case: Reached the destination
        if (i == m - 1 && j == n - 1) {
            return 1;
        }

        // Boundary Check: Out of bounds, no path possible
        if (i >= m || j >= n) {
            return 0;
        }

        // Memoization: Check if result is already calculated
        if (mpp[i][j] != -1) {
            return mpp[i][j];
        }

        // Recursion: Explore paths down and right
        return mpp[i][j] = solve(m, n, i + 1, j, mpp) + solve(m, n, i, j + 1, mpp);
    }

public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> mpp(m, vector<int>(n, -1)); // Initialize with -1
        return solve(m, n, 0, 0, mpp);
    }
};