class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int r=rowSum.size();
        int c=colSum.size();
        vector<vector<int>>ans(r,vector<int>(c,0));
        int i=0;
        int j=0;
        while(i<r &&j<c){
            if(rowSum[i]>colSum[j]){
                ans[i][j]=colSum[j];
                rowSum[i]-=colSum[j];
                j++;
            }
            else{
                ans[i][j]=rowSum[i];
                colSum[j]-=rowSum[i];

                i++;
            }
        }
        return ans;

    }
};