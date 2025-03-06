class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size()*grid.size()+1;
        vector<int> ans(n);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                ans[grid[i][j]]++;
            }
        }
        int miss;
        vector<int>rett;
        for(int i=1;i<n;i++){
            if(ans[i]==0){
                miss=i;
            }
            if(ans[i]>1){
                rett.push_back(i);
               
            }
            
        }
        rett.push_back(miss);
        return rett;
        
    }
   
};