class Solution {
private:
    int solve(int m, int n) {
        vector<vector<int>> mpp(m, vector<int>(n, 0)); 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    mpp[i][j]=1;
                }
                else{
                    int left=0;
                    int up=0;
                    if(i>0){
                        up=mpp[i-1][j];
                    }
                    if(j>0){
                        left=mpp[i][j-1];
                    }
                    mpp[i][j]=left+up;
                    
                }
            }
        }
        return mpp[m-1][n-1];

    }

public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> mpp(m, vector<int>(n, -1)); // Initialize with -1
        return solve(m, n);
    }
};