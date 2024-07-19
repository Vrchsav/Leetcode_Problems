class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int max_index=0;
        for(int i=1;i<nums.size();i++){
            if(nums[max_index]<nums[i]){
                max_index=i;
            }
        }
        if(max_index==0){
            swap(nums[max_index],nums[nums.size()-1]);
        }
        else{
            swap(nums[max_index],nums[max_index-1]);
        }
        return;
    }
};