class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        int ans=-1;
        for(auto h:nums){
            if(h==1){
                count++;
                ans=max(ans,count);

            }
            else{
                count=0;
            }
        }
        if(ans==-1){
            if(nums[0]==0) return 0;
            return nums.size();
        }
        return ans;
    }
};