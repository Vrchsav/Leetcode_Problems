class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        map<int,pair<int,int>>mpp;
        int n=mat.size();
        int m=mat[0].size();
        vector<int>row(m,0);
        vector<int>col(n,0);


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mpp[mat[i][j]]={i,j};
                row[j]+=mat[i][j];
                col[i]+=mat[i][j];

            }
        }
        for(int i=0;i<arr.size();i++){
            int ele=arr[i];
            pair<int,int>temp=mpp[ele];
            row[temp.second]-=ele;
            col[temp.first]-=ele;
            if( row[temp.second]==0 ||  col[temp.first]==0){
                return i;
            }


        }
        return -1;




        
    }
};