class Solution {
    void bfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = 1;
        while (!q.empty()) {
            pair<int, int> top = q.front();
            q.pop();
            
            // Check right
            if (top.second + 1 < m && grid[top.first][top.second + 1] == '1' && visited[top.first][top.second + 1] == 0) {
                q.push({i, top.second + 1});
                visited[i][top.second + 1] = 1;
            }
            
            // Check up
            if (top.first - 1 >= 0 && grid[top.first - 1][top.second] == '1' && visited[top.first - 1][top.second] == 0) {
                q.push({top.first - 1, top.second});
                visited[top.first - 1][top.second] = 1;
            }
            
            // Check down
            if (top.first + 1 < n && grid[top.first + 1][top.second] == '1' && visited[top.first + 1][top.second] == 0) {
                q.push({top.first + 1, top.second});
                visited[top.first + 1][top.second] = 1;
            }
            
            // Check left
            if (top.second - 1 >= 0 && grid[top.first][top.second - 1] == '1' && visited[top.first][top.second - 1] == 0) {
                q.push({top.first, top.second - 1});
                visited[top.first][top.second - 1] = 1;
            }
        }
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If the current cell is land ('1') and not yet visited
                if (grid[i][j] == '1' && visited[i][j] == 0) {
                    ans++;  // Increment the island count
                    bfs(grid, visited, i, j);
                }
            }
        }
        return ans;
        }
 } ;
