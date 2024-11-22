class Solution {
    void solve(vector<int>& nums, int target,int i,int current_sum,int &ans){
        if (i == nums.size()) {
        // Check if the current sum matches the target
        if (current_sum == target) {
            ans++;
        }
        return;
    }
        
        int plus=current_sum+nums[i];
        solve(nums,target,i+1,plus,ans);
        int sub=current_sum-nums[i];
        solve(nums,target,i+1,sub,ans);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans=0;
        solve(nums,target,0,0,ans);
        return ans;
    }
};