class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        int i=0;
        while(i<n){
            bool flag=false;
            for(int j=i;j<n;j++){
                if(nums[i]>nums[j] && nums[i]-nums[j]<=limit){
                    swap(nums[i],nums[j]);
                    flag=true;
                }
            }
            if(flag==false){
                i++;
            }

        }
        return nums;
        
    }
};