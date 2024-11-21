class Solution {
private:
    int solve(vector<vector<int>>& grid,int i,int j,  vector<vector<int>>dp){
        if(i==0 && j==0){
            return grid[0][0];
        }
        if(i<0 || j<0){
            return 1e9;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int up = grid[i][j]+ solve(grid,i-1,j,dp);
        int left= grid[i][j]+ solve(grid,i,j-1,dp);
        
        return dp[i][j]=min(up,left);

    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row=grid.size();
        if(row==0) return 0;
        int col=grid[0].size();
        vector<vector<int>>dp(row,vector<int>(col,-1));
        return solve(grid,row-1,col-1,dp);

        
    }
};