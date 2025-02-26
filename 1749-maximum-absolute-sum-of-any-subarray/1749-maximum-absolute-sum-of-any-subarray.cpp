class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans=-1;
        int count=0;

        for(int i=0;i<nums.size();i++){
            count+=nums[i];
            ans=max(count,ans);
            if(count<=0){
                count =0;
            }

        }
        count=0;
         for(int i=0;i<nums.size();i++){
            count+=nums[i];
            ans=max(abs(count),ans);
            if(count>0){
                count =0;
            }


        }
        return ans;
        
    }
};