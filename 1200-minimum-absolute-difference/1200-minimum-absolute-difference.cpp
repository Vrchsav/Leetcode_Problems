class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
         vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int minn=INT_MAX;
        int k=2;
        for(int i=0;i<nums.size();i++){
            if(i+k-1>=nums.size()){
                break;
            }
            
            minn=min(minn,nums[i+k-1]-nums[i]);
            
        }

        for(int i=0;i<nums.size();i++){
            if(i+k-1>=nums.size()){
                break;
            }
            if ((nums[i+k-1]-nums[i])==minn){
                ans.push_back({nums[i],nums[i+k-1]});
            }
            
            
            
        }
        return ans ;

    }
};