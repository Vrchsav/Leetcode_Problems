class Solution {
public:
    int largestInteger(vector<int> &nums, int k) {
        int n = nums.size();
        if (k == n) {
            return *std::max_element(nums.begin(), nums.end());
        }

        unordered_map<int, int> subarray_appearance_map;

        // Loop through the starting index 'i' of every possible window
        for (int i = 0; i <= n - k; i++) {
            // Use a set to make sure we only count each number ONCE per window
            unordered_set<int> unique_in_window;
            
            for (int j = i; j < i + k; j++) {
                unique_in_window.insert(nums[j]);
            }

            // Increment the global map for elements present in this specific window
            for (int num : unique_in_window) {
                subarray_appearance_map[num]++;
            }
        }

        int ans = -1;
        for (const auto &pair : subarray_appearance_map) {
            if (pair.second == 1) {
                ans = max(ans, pair.first);
            }
        }
        return ans;
    }
};
