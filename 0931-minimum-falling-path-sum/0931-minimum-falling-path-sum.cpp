class Solution {
    int solve(vector<vector<int>>& matrix,int i,int j,vector<vector<int>>& dp){
        
        if (j < 0 || j >= matrix[0].size()) {
        return 1e9;  
    }
    if(i==0){
            return matrix[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        //up
        int up=matrix[i][j]+solve(matrix,i-1,j,dp);
        //left diagonal
        int left=matrix[i][j]+solve(matrix,i-1,j-1,dp);

        //right diagonal
        int right=matrix[i][j]+solve(matrix,i-1,j+1,dp);

        return dp[i][j]=min(up,min(right,left));

    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        int ans=INT_MAX;
        for(int i=0;i<col;i++){
            vector<vector<int>>dp(row,vector<int>(col,-1));
            ans=min(ans,solve(matrix,row-1,i,dp));
        }
        return ans;
        
    }
};