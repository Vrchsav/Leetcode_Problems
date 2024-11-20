class Solution {
    int solve(vector<vector<int>>& Grid,int row,int col){
        vector<vector<int>>dp(row,vector<int>(col,-1));

        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i==0 && j==0){
                    dp[i][j]=1;
                }
                else{
                
                int up=0;
                if(i>0 && Grid[i-1][j]!=1){
                    up=dp[i-1][j];
                }
                int left=0;
                 if(j>0 && Grid[i][j-1]!=1){
                    left=dp[i][j-1];
                    }
                dp[i][j]=left+up;
                
            }}
        }
        
        
        return dp[row-1][col-1];
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        int row=Grid.size();
        int col=Grid[0].size();
        if(Grid[row-1][col-1]==1) return 0;
        return solve(Grid,row,col);
    }
};