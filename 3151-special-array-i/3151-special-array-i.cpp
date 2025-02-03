class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if(nums.size()==2){
            if((nums[0]%2==0 && (nums[1]%2==0) || (nums[0]%2!=0 && (nums[1]%2!=0 )))){
return false;
        }}
        for(int i=1;i<nums.size()-1;i++){

            if((nums[i]%2==0 && (nums[i-1]%2==0 || nums[i+1]%2==0)) || (nums[i]%2!=0 && (nums[i-1]%2!=0 || nums[i+1]%2!=0))  ){
return false;
            }

        }
        return true;
    }
};