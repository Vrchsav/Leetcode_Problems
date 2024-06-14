class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int current_no=nums[0];
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(current_no<nums[i]){
                current_no=nums[i];
            }
            ans+=abs(current_no-nums[i]);
            current_no++;
        }
        return ans;
    }
};