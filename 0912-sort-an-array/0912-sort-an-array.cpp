class Solution {
    void merge(vector<int>&nums,int low,int high,int mid){
        vector<int>ans;
        int i=low;
        int j=mid+1;
        while(i<=mid && j<=high){
            if(nums[i]>nums[j]){
                ans.push_back(nums[j]);
                j++;
            }
            else{
                ans.push_back(nums[i]);
                i++;
            }
        }
        while(i<=mid ){
            ans.push_back(nums[i]);
            i++;
        }
        while(j<=high){
            ans.push_back(nums[j]);
            j++;
        }
        for (int k = 0; k < ans.size(); k++) {
            nums[low + k] = ans[k];
        }
    
        return;
    }
    void merge_sort(vector<int>&nums,int low,int high){
        if(high==low){
            return ;
        }
        int mid=(low+high)/2;
        merge_sort(nums,low,mid);
        merge_sort(nums,mid+1,high);
        merge(nums,low,high,mid);

    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size()-1;
      merge_sort(nums,0,n);
      return nums;
    
    }
};