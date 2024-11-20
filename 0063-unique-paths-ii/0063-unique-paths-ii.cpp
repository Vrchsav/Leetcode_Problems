class Solution {
    int solve(vector<vector<int>>& Grid,int i,int j,vector<vector<int>>&dp){
        if(i==0 && j==0){
            return 1;
        }
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int up=0;
        if(i-1>=0 && Grid[i-1][j]!=1){
            up=solve(Grid,i-1,j,dp);
        }
        int left=0;
        if(j-1>=0 && Grid[i][j-1]!=1){
            left=solve(Grid,i,j-1,dp);
        }
        return dp[i][j]=left+up;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        int row=Grid.size();
        int col=Grid[0].size();
        if(Grid[row-1][col-1]==1) return 0;
        vector<vector<int>>dp(row,vector<int>(col,-1));
        return solve(Grid,row-1,col-1,dp);
    }
};