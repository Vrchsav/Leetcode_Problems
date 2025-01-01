#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    int maxSum(vector<int>& front_sum, int k, int h, int i, vector<vector<int>>& memo) {
        int n = front_sum.size();
        if (h == 0 || i >= n) {
            return 0;
        }

        // Check memoized result
        if (memo[i][h] != -1) {
            return memo[i][h];
        }

        // Compute "include" and "exclude" cases
        int inc = front_sum[i] + maxSum(front_sum, k, h - 1, i + k, memo);
        int not_inc = maxSum(front_sum, k, h, i + 1, memo);

        // Store result in memo and return
        return memo[i][h] = max(inc, not_inc);
    }

    void findpath(vector<int>& front_sum, int sum, int count, int i, vector<int>& ans, int k, vector<vector<int>>& memo) {
        if (count == 0 || i >= front_sum.size()) {
            return;
        }

        int include = front_sum[i] + maxSum(front_sum, k, count - 1, i + k, memo);
        int exclude = maxSum(front_sum, k, count, i + 1, memo);

        if (include >= exclude) {
            ans.push_back(i); // Include the current index
            findpath(front_sum, sum - front_sum[i], count - 1, i + k, ans, k, memo);
        } else {
            findpath(front_sum, sum, count, i + 1, ans, k, memo);
        }
    }

public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> front_sum(n, 0);
        int sum = 0;
        int last_num = 0;

        // Calculate sliding window sums
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        front_sum[last_num] = sum;
        for (int i = k; i < nums.size(); i++) {
            sum += nums[i];
            sum -= nums[last_num];
            last_num++;
            front_sum[last_num] = sum;
        }

        // Memoization table for maxSum
        vector<vector<int>> memo(n, vector<int>(4, -1)); // 4 because h is at most 3
        int max_sum = maxSum(front_sum, k, 3, 0, memo);

        // Find the indices of the subarrays contributing to the maximum sum
        vector<int> ans;
        findpath(front_sum, max_sum, 3, 0, ans, k, memo);

        return ans;
    }
};
