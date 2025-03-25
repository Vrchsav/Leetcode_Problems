#include <vector>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Ensure intervals are sorted by start time for efficient merging
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        int start = intervals[0][0];
        int end = intervals[0][1];

        // Iterate through intervals, considering both start and end times for merging
        for (int i = 1; i < intervals.size(); i++) {
            int currentStart = intervals[i][0];
            int currentEnd = intervals[i][1];

            // Check for overlap or consecutive intervals
            if (currentStart <= end) {
                // Update end time to include the larger ending interval
                end = std::max(end, currentEnd);
            } else {
                // No overlap, push the current merged interval and start processing the new one
                result.push_back({start, end});
                start = currentStart;
                end = currentEnd;
            }
        }

        // Push the last merged interval if applicable
        result.push_back({start, end});

        return result;
    }
};
