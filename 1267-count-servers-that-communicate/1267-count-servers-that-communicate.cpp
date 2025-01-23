class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> row(m, 0);
        vector<int> col(n, 0);
        queue < pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    col[j]++;
                    row[i]++;
                    q.push({i, j});
                }
            }
        }

        int ans = 0;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (row[x] > 1 || col[y] > 1) {
                ans++;
            }
        }

        return ans;
    }
};