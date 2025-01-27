class Solution {
    int solve(vector<int>& nums,int target, vector<vector<int>>&dp,int i){
        
        if (target==0){
            return 1;
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        int count=0;
        for(int j=0;j<nums.size();j++){
            if(target>=nums[j]){
                count+=solve(nums,target-nums[j],dp,j);
            }
        }

        return dp[i][target] =count;

    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        int ans;
        ans=solve(nums,target,dp,0);
        return ans;

        
    }
};