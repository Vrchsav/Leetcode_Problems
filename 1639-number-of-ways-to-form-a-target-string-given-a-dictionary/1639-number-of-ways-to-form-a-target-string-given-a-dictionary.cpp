class Solution {
    const int MOD = 1e9 + 7;

    int solve(string &target, int target_index, vector<vector<int>>& hash, int i, int &n, vector<vector<int>>& dp) {
        if (target_index == target.size()) {
            return 1; // Successfully formed the target
        }
        if (i == n) {
            return 0; // Exhausted all columns
        }
        if (dp[target_index][i] != -1) {
            return dp[target_index][i]; // Use cached result
        }

        int inc = 0;
        if (hash[target[target_index] - 'a'][i] != 0) {
            // Multiply count of valid choices and recurse
            inc = (1LL * hash[target[target_index] - 'a'][i] * solve(target, target_index + 1, hash, i + 1, n, dp)) % MOD;
        }
        int not_inc = solve(target, target_index, hash, i + 1, n, dp) % MOD;

        // Store and return the result
        return dp[target_index][i] = (not_inc + inc) % MOD;
    }

public:
    int numWays(vector<string>& words, string target) {
        int n = words.size();
        int m = target.size();
        int l = words[0].size();

        // Build the frequency table
        vector<vector<int>> hash(26, vector<int>(l, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < words[i].size(); j++) {
                char charr = words[i][j];
                hash[charr - 'a'][j]++;
            }
        }

        // Initialize DP table
        vector<vector<int>> dp(m, vector<int>(l, -1));

        // Compute the result
        return solve(target, 0, hash, 0, l, dp);
    }
};
