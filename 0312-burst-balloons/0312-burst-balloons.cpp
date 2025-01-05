
class Solution {
    const int MOD = 1e9 + 7;
    int solve(vector<int>& nums, int i, int j, vector<vector<int>> &dp) {
        if (i > j) {
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int maxi = INT_MIN;
        for (int k = i; k <= j; k++) {
            int a = nums[k] * nums[i - 1] * nums[j + 1] +
                    solve(nums, i, k - 1,dp) + solve(nums, k + 1, j,dp);
            maxi = max(maxi, a) % MOD;
        }
        return dp[i][j]=maxi % MOD;
    }

public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));

        int ans = solve(nums, 1, n,dp);
        return ans;
    }
};