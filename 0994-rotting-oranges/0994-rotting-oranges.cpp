class Solution {
public:
    void bsf(int row, int col, vector<vector<int>>& visited, vector<vector<int>>& grid, int& ans, queue<pair<int, int>>& q) {
        vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        while (!q.empty()) {
            int size = q.size(); // Process all rotten oranges at this level
            bool flag = false;

            for (int i = 0; i < size; i++) {
                pair<int, int> top = q.front();
                q.pop();
                int r = top.first;
                int c = top.second;

                for (int j = 0; j < 4; j++) {
                    int next_r = r + dir[j].first;
                    int next_c = c + dir[j].second;

                    if (next_r >= 0 && next_r < visited.size() && next_c >= 0 &&
                        next_c < visited[0].size() && visited[next_r][next_c] == 0 &&
                        grid[next_r][next_c] == 1) {
                        flag = true;
                        q.push({next_r, next_c});
                        visited[next_r][next_c] = 1;
                    }
                }
            }

            if (flag) {
                ans++;
            }
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<int>> visited(m, vector<int>(n, 0)); // 0 == not visited
        queue<pair<int, int>> q;

        // Enqueue all initially rotten oranges
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    visited[i][j] = 1;
                }
            }
        }

        // Perform BFS
        bsf(0, 0, visited, grid, ans, q);

        // Check for any remaining fresh oranges
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && visited[i][j] == 0) {
                    return -1;
                }
            }
        }

        return ans;
    }
};
