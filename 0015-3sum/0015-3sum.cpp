class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int ele1=-1;
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            ele1=i;
            int ele2=i+1;
            int ele3=nums.size()-1;
            while(ele2<ele3){
                int sum=nums[ele1]+nums[ele2]+nums[ele3];
                if(sum==0){
                    ans.push_back({nums[ele1],nums[ele2],nums[ele3]});
                    ele2++;
                    ele3--;
                    while(ele2<ele3 && nums[ele2]==nums[ele2-1]) ele2++;
                    while(ele2<ele3 && nums[ele3]==nums[ele3+1]) ele3--;

                }
                else if(sum<0){
                    ele2++;
                }
                else{
                    ele3--;
                }
            }
        

        }
        return  ans;
    }
};