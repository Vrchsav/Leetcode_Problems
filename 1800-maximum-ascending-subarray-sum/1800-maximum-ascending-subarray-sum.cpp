class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans=0;
        int count=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                count+=nums[i];
            }
            else{
                ans=max(ans,count);
                count=nums[i];
            }

        }
                ans=max(ans,count);

        return ans;
    }
};