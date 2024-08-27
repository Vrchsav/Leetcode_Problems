class Solution {
private:
    void solve(vector<int>nums,vector<int>ds, vector<vector<int>>&ans, vector<bool>freq){
       if( ds.size()==nums.size()){
        ans.push_back(ds);
        return;
       }
       for(int i=0;i<nums.size();i++){
        if(freq[i]){
            freq[i]=false;
            ds.push_back(nums[i]);
            solve(nums,ds,ans,freq);
            freq[i]=true;
            ds.pop_back();

        }
       }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        vector<bool>freq(nums.size(),true);
        solve(nums,ds,ans,freq);
        return ans;
    }
};