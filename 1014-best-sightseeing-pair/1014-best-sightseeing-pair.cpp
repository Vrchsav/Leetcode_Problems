class Solution {
    int solve(vector<int>values,int count,int index){
        if(count ==0  || index<0){
            return 0;
        }
        
        int inc =0;
        if(count==1){
            inc=values[index]+index+solve(values,count-1,index-1);
        }
        if(count==2){
            inc=values[index]-index+solve(values,count-1,index-1);

        }
        int not_inc=solve(values,count,index-1);
        return max(inc,not_inc);
    }
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        int ans=solve(values,2,n-1);
        return ans;
    }
};