class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int h=-1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                h=i;
                break;
            }
            }
            if(h==-1){
                reverse(nums.begin(),nums.end());

                return ;
            }
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]>nums[h]){
                swap(nums[i],nums[h]);
                reverse(nums.begin()+h+1,nums.end());

                return;
            }
        }
        
    }
};