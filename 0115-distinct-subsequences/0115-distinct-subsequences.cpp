class Solution {
    const long long MOD = 1e9 + 7;
    int solve(string s, string t, int n1, int n2) {
        vector<vector<long long >> dp(n1 + 1, vector<long long>(n2 + 1, 0));

        for (int i = 0; i <= n1; i++) {
            dp[i][0] = 1;  // Empty target string
        }
        

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                long long inc = 0;
                if ( s[i-1] == t[j-1]) {
                    inc = dp[i-1][j-1];
                }
                long long not_inc = dp[i-1][j];
                dp[i][j] = (inc + not_inc) %MOD;
            }
        }
        return dp[n1][n2];
    }

public:
    int numDistinct(string s, string t) {
        int ans = 0;
        int n1 = s.size();
        int n2 = t.size();
        return solve(s, t, n1 , n2 );
    }
};