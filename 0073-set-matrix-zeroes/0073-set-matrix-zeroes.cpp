class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        set<int>x;
        set<int>y;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    x.insert(i);
                    y.insert(j);
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(x.find(i)!=x.end() || y.find(j)!=y.end()){
                matrix[i][j]=0;
                }
            }
        }

        
    }
};