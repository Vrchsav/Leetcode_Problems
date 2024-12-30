class Solution {
    void solve(int &low, int &high, int &zero, int &one, int len, int &ans, vector<int> &dp) {
    const int MOD = 1e9 + 7;

    // Base Case: Stop if length exceeds high
    if (len > high) {
        return;
    }

    // Memoization Check
    if (dp[len] != -1) {
        ans = (ans + dp[len]) % MOD;
        return;
    }

    // Initialize count for current length
    int currentCount = 0;

    // Count valid strings for the current length
    if (len >= low && len <= high) {
        currentCount++;
    }

    // Recur for the next lengths
    solve(low, high, zero, one, len + zero, currentCount, dp);
    solve(low, high, zero, one, len + one, currentCount, dp);

    // Update memoization and answer, ensuring modulo is applied
    dp[len] = currentCount % MOD;
    ans = (ans + currentCount) % MOD;
}


public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int ans = 0;
        vector<int>dp(high+1,-1);
        solve(low, high, zero, one, 0,ans,dp);
        return ans;
    }
};