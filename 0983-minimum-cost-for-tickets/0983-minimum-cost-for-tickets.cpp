class Solution {
    int solve(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1, 0); // dp[i] represents the minimum cost to cover all days starting from day i
        
        // Iterate from the last day to the first
        for (int i = n - 1; i >= 0; i--) {
            // Option 1: Buy a 1-day pass
            int day1Cost = costs[0] + dp[i + 1];

            // Option 2: Buy a 7-day pass
            int j = i;
            while (j < n && days[j] < days[i] + 7) {
                j++;
            }
            int day7Cost = costs[1] + dp[j];

            // Option 3: Buy a 30-day pass
            int k = i;
            while (k < n && days[k] < days[i] + 30) {
                k++;
            }
            int day30Cost = costs[2] + dp[k];

            // Take the minimum of all three options
            dp[i] = min(day1Cost, min(day7Cost, day30Cost));
        }

        // The answer is the minimum cost to cover all days starting from the first
        return dp[0];
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int ans=0;
        ans=solve(days,costs);
        return ans;
    }
};