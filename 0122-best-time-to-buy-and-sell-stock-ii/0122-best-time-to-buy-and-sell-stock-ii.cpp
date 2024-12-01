class Solution {
    int solve(vector<int>& prices, int i, bool flag,vector<vector<int>>&dp) {

        if (i >=prices.size()) {
            return 0;
        }
        
        if(dp[i][int(flag)]!=-1){
            return dp[i][int(flag)];
        }
        if (flag == true) {
            int buy = -prices[i] + solve(prices, i + 1, false,dp);

            int do_nothing = solve(prices, i + 1, true,dp);
            return  dp[i][int(flag)]=max(do_nothing, buy);
        }
 
        else {
            int sell = prices[i] + solve(prices, i + 1, true,dp);
            int do_nothing = solve(prices, i + 1, false,dp);
            return dp[i][int(flag)]=  max(do_nothing, sell);
        }

    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solve(prices, 0, true,dp);
    }
};