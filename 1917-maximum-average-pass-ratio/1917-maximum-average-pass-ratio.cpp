class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        
        auto gain = [](const vector<int>& cls) {
            int pass = cls[0], total = cls[1];
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        };

        priority_queue<pair<double, vector<int>>> maxHeap;
        for (const auto& cls : classes) {
            maxHeap.push({gain(cls), cls});
        }

        while (extraStudents--) {
            auto top = maxHeap.top();
            maxHeap.pop();
            auto cls = top.second;
            cls[0]++; // Add one passing student
            cls[1]++; // Increase total students
            maxHeap.push({gain(cls), cls});
        }

        double totalAvg = 0;
        while (!maxHeap.empty()) {
            auto cls = maxHeap.top().second;
            maxHeap.pop();
            totalAvg += (double)cls[0] / cls[1];
        }

        return totalAvg / classes.size();
    }
};