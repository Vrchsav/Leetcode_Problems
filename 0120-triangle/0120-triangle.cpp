class Solution {
    int solve(vector<vector<int>>& grid,int i,int j,vector<vector<int>>&dp){
        if(i==grid.size()-1 && j<grid[i].size()){
            return grid[i][j];
        }
        if(i<0 || j<0){
            return 1e9;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int down = grid[i][j]+ solve(grid,i+1,j,dp);
        int diagonal= grid[i][j]+ solve(grid,i+1,j+1,dp);
        
        return dp[i][j]=min(down,diagonal);

    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row=triangle.size();
        if(row==0) return 0;
        int col=triangle[row-1].size();
        vector<vector<int>>dp(row,vector<int>(row,-1));
        return solve(triangle,0,0,dp);
        
    }
};