class Solution {
public:
    bool check(vector<int>& nums) {
        int inc=0;
        int des=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<=nums[i]){
                inc++;
            }else{
                des++;
            }
        }
        if(nums[nums.size()-1]<=nums[0]){
            inc++;
        }else{
            des++;
        }
        if(des>1){
            return false;
        }
        return true;
    }
};