class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int start=0;
        int end=n-1;
        while(start<end){
            int mid=(start+end)/2;
            if(mid-1>=0 && nums[mid]==nums[mid-1]){
                if(mid%2!=0){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
            else if (mid+1<n && nums[mid]==nums[mid+1]){
                 if(mid%2==0){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
            else{
                return nums[mid];
            }
        }
        return nums[end];
    }
};