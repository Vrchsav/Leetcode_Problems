class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=1;i<matrix.size();i++){
            if(matrix[i][0]>=target){
                if(target==matrix[i][0]){
                    return true;
                }
                for(int j=0;j<matrix[0].size();j++){
                    if(matrix[i-1][j]==target){
                        return true;
                    }
                }
            }
        }
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[0][j]==target){
                        return true;
                    }
        }

        return false;
    }
};