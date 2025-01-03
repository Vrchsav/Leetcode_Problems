class Solution {
     const int MOD=1e9+7;

    
    int solve(int i, int j, vector<int>& cuts) {
        if (i > j) {
            return 0;
        }
        
        int ans = INT_MAX;
        
        for (int k = i; k <= j; k++) {
            int cost = cuts[j + 1] - cuts[i - 1] 
                     + solve(i, k - 1, cuts) 
                     + solve(k + 1, j, cuts);
            ans = min(ans, cost % MOD);
        }
        
        return ans % MOD;
    }

public:
    int minCost(int n, vector<int> &cuts) {
        int m=cuts.size();
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        return solve(1,m,cuts);

        
    }
};
