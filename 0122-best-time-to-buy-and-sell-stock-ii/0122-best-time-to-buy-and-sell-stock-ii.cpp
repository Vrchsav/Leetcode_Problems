class Solution {
    int solve(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[n][0] = 0;
        dp[n][1] = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= 1; j++) {
                if (j) {
                    int buy = -prices[i] + dp[i+1][0];
                    int do_nothing =  dp[i+1][1];
                    dp[i][j] = max(do_nothing, buy);
                }

                else {
                    int sell = prices[i] +dp[i+1][1];
                    int do_nothing = dp[i+1][0];
                     dp[i][j] = max(do_nothing, sell);
                }
            }
        }
        return dp[0][1];
    }

public:
    int maxProfit(vector<int>& prices) {
        
        return solve(prices);
    }
};