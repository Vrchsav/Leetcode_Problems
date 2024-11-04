class Solution {
    void bfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = 1;
        
        // Define the four possible directions: right, left, down, up
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        while (!q.empty()) {
            pair<int, int> top = q.front();
            q.pop();
            
            for (auto dir : directions) {
                int new_i = top.first + dir.first;
                int new_j = top.second + dir.second;
                
                // Check if the new cell is within bounds, is land ('1'), and is not visited
                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && 
                    grid[new_i][new_j] == '1' && visited[new_i][new_j] == 0) {
                    
                    q.push({new_i, new_j});
                    visited[new_i][new_j] = 1;
                }
            }
        }
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
