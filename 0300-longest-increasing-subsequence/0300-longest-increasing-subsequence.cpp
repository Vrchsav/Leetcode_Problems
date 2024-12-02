class Solution {
    int solve(vector<int>& nums,int i,int num,vector<vector<int>>&dp){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i][num+1]!=-1){
            return  dp[i][num+1];
        }
        int include=0;
        if(num==-1 || nums[i]>nums[num]){
            include=1+solve(nums,i+1,i,dp);
        }
        
           int not_inc=solve(nums,i+1,num,dp);
        
        return  dp[i][num+1]= max(include,not_inc);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(nums,0,-1,dp);
    }
};