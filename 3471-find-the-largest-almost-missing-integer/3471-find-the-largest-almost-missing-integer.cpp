class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        // Case 1: Window size matches array size
        if (k == n) {
            return *std::max_element(nums.begin(), nums.end());
        }

        // Count overall frequencies of every number in O(N) time
        unordered_map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }

        // Case 2: Window size is 1
        // Look for the maximum number that appears exactly once overall
        if (k == 1) {
            int ans = -1;
            for (int num : nums) {
                if (counts[num] == 1) {
                    ans = max(ans, num);
                }
            }
            return ans;
        }

        // Case 3: 1 < k < n
        // Only the absolute first or last elements can belong to exactly one subarray.
        // They can only belong to one subarray if they are completely unique in the array.
        int ans = -1;
        if (counts[nums[0]] == 1) {
            ans = max(ans, nums[0]);
        }
        if (counts[nums[n - 1]] == 1) {
            ans = max(ans, nums[n - 1]);
        }

        return ans;
    }
};
