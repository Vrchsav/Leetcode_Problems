class Solution {

public:
    vector<vector<int>> merge(vector<vector<int>>& interval) {
        vector<vector<int>> ans;

        sort(interval.begin(), interval.end());
        ans.push_back(interval[0]);
        for (int i = 1; i < interval.size(); i++) {
            if (interval[i][0] < ans.back()[1]) {
                ans.back()[1] = max(ans.back()[1], interval[i][1]);
            } else {
                ans.push_back(interval[i]);
            }
        }
        return ans;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {

        vector<vector<int>> horizontal;
        vector<vector<int>> vertical;

        for (int i = 0; i < rectangles.size(); i++) {
            int sx = rectangles[i][0];
            int sy = rectangles[i][1];
            int ex = rectangles[i][2];
            int ey = rectangles[i][3];

            horizontal.push_back({sy, ey});
            vertical.push_back({sx, ex});
        }
        horizontal = merge(horizontal);
        vertical = merge(vertical);

        if (vertical.size() > 2 || horizontal.size() > 2) {
            return true;
        }

        return false;
    }
};