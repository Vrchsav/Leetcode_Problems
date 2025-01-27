class Solution {
    int solve(vector<int>& nums,int target){
        
        if (target==0){
            return 1;
        }
        int count=0;
        for(auto a:nums ){
            if(target>=a){
                count+=solve(nums,target-a);
            }
        }

        return count;

    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        int ans;
        ans=solve(nums,target);
        return ans;

        
    }
};