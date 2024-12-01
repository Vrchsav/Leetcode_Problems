class Solution {
    int solve(vector<int>& prices, int cap ,bool buy,int i,vector<vector<vector<int>>>&dp) {

        if (i >= prices.size() || cap==0) {
            return 0;
        }
        if(dp[i][int(buy)][cap] !=-1){
            return dp[i][int(buy)][cap];
        }
        if (buy) {
            
            int buyy = -prices[i] + solve(prices, cap,false, i + 1,dp);
            int nott = solve(prices, cap,true, i + 1,dp);
            return   dp[i][int(buy)][cap] = max(buyy, nott);
        } else {
            
            int sel = prices[i] + solve(prices,cap-1,true, i + 1,dp);
            int nott = solve(prices,cap,false, i + 1,dp);
            return dp[i][int(buy)][cap]=max(sel, nott);
        }
    }

public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(); 
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(prices, 2,true, 0,dp); 
        }
};

