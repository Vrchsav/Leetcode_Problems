class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Step 1: Sort envelopes by width ASC, height DESC
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });

        // Step 2: Find LIS on heights
        vector<int> dp;
        for (auto& envelope : envelopes) {
            int h = envelope[1];
            auto it = lower_bound(dp.begin(), dp.end(), h);
            if (it == dp.end()) {
                dp.push_back(h);
            } else {
                *it = h;
            }
        }
        return dp.size();
    }
};
