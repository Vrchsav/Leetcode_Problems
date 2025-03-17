class Solution {
public:
    bool divideArray(vector<int>& nums) {
         sort(nums.begin(),nums.end());
         int i=1;
         int ans=0;
         while(i<nums.size()){
            if(nums[i]==nums[i-1]){
                i+=2;
                ans++;
            }else{
                i++;
            }
         }
         return ans*2==nums.size();
        
    }
};