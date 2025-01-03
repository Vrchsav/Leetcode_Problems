class Solution {
    const int MOD = 1e9 + 7;

    int solve( int m, vector<int>& cuts ) {

        vector<vector<int>> dp(m + 2, vector<int>(m + 2, 0));

        for (int i = m; i > 0; i--) {
            for (int j =  1; j <= m; j++) {
                if(i>j){
                    continue;
                }
                int ans = INT_MAX;

                for (int k = i; k <= j; k++) {
                    int cost = cuts[j + 1] - cuts[i - 1] +dp[i][k-1]+dp[k+1][j];
                               
                    ans = min(ans, cost % MOD);
                }

             dp[i][j] = ans % MOD;
            }
        }
        return dp[1][m];
    }

public:
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, -1));
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        return solve( m, cuts);
    }
};
