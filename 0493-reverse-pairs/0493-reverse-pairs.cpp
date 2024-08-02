class Solution {
    int merge(vector<int>&nums,int low,int high,int mid){
        vector<int>ans;
        int idx=low;
        int i=low;
        int j=mid+1;
        int count=0;
        while(i<=mid && j<=high){
            if(nums[i]>=nums[j]){
                ans.push_back(nums[j]);
                while(idx<=mid){
                    if((long long)nums[idx]>(long long)2*nums[j]){
                        count+=mid-idx+1;
                        break;
                    }
                    else{
                        idx++;
                    }
                }
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
    
        return count ;
    }
    int  merge_sort(vector<int>&nums,int low,int high){
        int ans=0;
        if(high==low){
            return ans ;
        }
        
        int mid=(low+high)/2;
        cout<<mid;
        ans+=merge_sort(nums,low,mid);
        ans+=merge_sort(nums,mid+1,high);
        ans+=merge(nums,low,high,mid);
        return ans;

    }
public:
    int reversePairs(vector<int>& nums) {
           int n=nums.size()-1;
            int ans=merge_sort(nums,0,n);
            return ans;
    }
};