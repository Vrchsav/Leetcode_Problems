class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;
        vector<pair<int, int>> path = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
        vector<vector<int>> visited(n, vector<int>(m, 0));
        // 0 = not_visited
        // 1 = viisted
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int count = 0;
                if (grid[i][j] != 0 && visited[i][j] == 0) {
                    q.push({i, j});
                    visited[i][j] = 1;
                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        count += grid[x][y];
                        for (int k = 0; k < 4; k++) {
                            pair<int, int> temp = path[k];
                            int next_x = x + temp.first;
                            int next_y = y + temp.second;

                            if (next_x >= 0 && next_x < n && next_y >= 0 &&
                                next_y < m && grid[next_x][next_y] != 0 &&
                                visited[next_x][next_y] == 0) {

                                q.push({next_x,next_y});
                                visited[next_x][next_y] = 1;

                            }
                        }
                    }
                    ans = max(count, ans);
                }
            }
        }
        return ans;
    }
};