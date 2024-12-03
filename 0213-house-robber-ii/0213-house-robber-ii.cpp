class Solution {
    int solve(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[0]=nums[0];
        for (int i = 1; i < n; i++) {
            int include = nums[i];
            if (i - 2 >= 0) {
                include +=   dp[i - 2];
            }
            int notinclude = dp[i - 1];

            dp[i] = max(include, notinclude);
        }
        return dp[n-1];
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }
        vector<int> temp1, temp2;
        for (int i = 0; i < nums.size(); i++) {
            if (i != 0) {
                temp1.push_back(nums[i]);
            }
            if (i != n - 1) {
                temp2.push_back(nums[i]);
            }
        }
        return max(solve(temp1), solve(temp2));
    }
};