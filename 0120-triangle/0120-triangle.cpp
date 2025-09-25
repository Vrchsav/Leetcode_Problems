class Solution {
    int solve(vector<vector<int>>& grid){
        int row=grid.size();
        int col=grid[row-1].size();

        vector<vector<int>>dp(row,vector<int>(row,0));

        for(int i=0;i<col;i++){
            dp[row-1][i]=grid[row-1][i];

        }
        
        for(int i=row-2;i>=0;i--){
            for(int j=grid[i].size()-1;j>=0;j--){
                int down=INT_MAX;
                if(i+1<row)
         down = grid[i][j]+ dp[i+1][j];
        int diagonal=INT_MAX;
        if(i+1<row && j+1<grid[i+1].size())
         diagonal= grid[i][j]+ dp[i+1][j+1];
         dp[i][j]=min(down,diagonal);

        }}
        return dp[0][0];

    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row=triangle.size();
        if(row==0) return 0;
        return solve(triangle);
        
    }
};