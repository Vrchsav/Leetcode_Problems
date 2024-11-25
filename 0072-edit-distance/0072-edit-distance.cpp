class Solution {
    int solve(string word1, string word2, int i, int j,   vector<vector<int>> &dp) {
        if (i < 0 && j >= 0) {
            return j + 1;
        }
        if (j < 0 && i >= 0) {
            return i + 1;
        }
        if (j < 0 && i < 0) {
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if (word1[i] == word2[j]) {
            return solve(word1, word2, i - 1, j - 1,dp);
        } else {
            int replace = 1 + solve(word1, word2, i - 1, j - 1,dp);
            int deletee = 1 + solve(word1, word2, i - 1, j,dp);
            int insert = 1 + solve(word1, word2, i, j - 1,dp);
            return dp[i][j]=(min(replace, min(deletee, insert)));
        }
    }

public:
    int minDistance(string word1, string word2) {
        int i = word1.size();
        int j = word2.size();
        vector<vector<int>> dp(i + 1, vector<int>(j + 1, -1));
        return solve(word1, word2, i - 1, j - 1, dp);
    }
};