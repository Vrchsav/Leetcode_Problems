class Solution {
    int solve(vector<int>&values,int count,int index,vector<vector<int>>&mpp){
        if(count ==0  || index<0){
            return 0;
        }
        if(mpp[count][index]!=-1){
            return mpp[count][index];
        }
        int inc =0;
        if(count==1){
            inc=values[index]+index+solve(values,count-1,index-1,mpp);
        }
        if(count==2){
            inc=values[index]-index+solve(values,count-1,index-1,mpp);

        }
        int not_inc=solve(values,count,index-1,mpp);
        return mpp[count][index] =max(inc,not_inc);
    }
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        vector<vector<int>>mpp(3,vector<int>(n,-1));
        int ans=solve(values,2,n-1,mpp);
        return ans;
    }
};