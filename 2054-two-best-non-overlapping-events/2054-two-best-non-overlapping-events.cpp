class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<vector<int>>mpp;
        for(auto &a:events){
            mpp.push_back({a[0],1,a[2]});
            mpp.push_back({a[1]+1,-1,a[2]});

        }
        sort(mpp.begin(),mpp.end());
        int maxSum=0;
        int left_sem=0;
        for(int i=0;i<mpp.size();i++){
            if(mpp[i][1]==1){
                maxSum=max(maxSum,left_sem+mpp[i][2]);
            }
            if(mpp[i][1]==-1){
                left_sem=max(left_sem,mpp[i][2]);
            }
        }
        return maxSum;
    }
};