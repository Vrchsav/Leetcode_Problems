class Solution {
     const int MOD=1e9+7;

    
    int solve(int i, int j, vector<int>& cuts,vector<vector<int>>&dp) {
        if (i > j) {
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int ans = INT_MAX;
        
        for (int k = i; k <= j; k++) {
            int cost = cuts[j + 1] - cuts[i - 1] 
                     + solve(i, k - 1, cuts,dp) 
                     + solve(k + 1, j, cuts,dp);
            ans = min(ans, cost % MOD);
        }
        
        return dp[i][j] =ans % MOD;
    }

public:
    int minCost(int n, vector<int> &cuts) {
        int m=cuts.size();
        vector<vector<int>>dp(m+1,vector<int>(m+1,-1));
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        return solve(1,m,cuts,dp);

        
    }
};
