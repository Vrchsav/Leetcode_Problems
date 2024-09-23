class Solution {
private:
    int findpivote(vector<int>& nums,int target){
        int start=0;
        int n=nums.size();
        int end=n-1;
        int mid;
        if(start==end && nums[0]==target){
            return 0;
        }
        while(start<=end){
            mid=(start+end)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>=nums[0]){
                if(target>=nums[0] && target<=nums[mid]){
                    end=mid-1;
                }
                else {
                    start=mid+1;
                }
            }
            else{
                if(nums[n-1]>=target && target>=nums[mid]){
                    start=mid+1;
                   }
                else{
                    end=mid-1;
                }
            }
        }
        return -1;
    }

public:
    int search(vector<int>& nums, int target) {

        int mid= findpivote( nums,target);
        return mid;
        
    }
};