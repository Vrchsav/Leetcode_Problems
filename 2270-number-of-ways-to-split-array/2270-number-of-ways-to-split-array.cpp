class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long>hash;
        long long sum=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            hash.push_back(sum);
            // cout<<sum<<" ";
        }
        int ans=0;
        for(int i=0;i<nums.size()-1;i++){
            
            if(hash[i]>=(hash[n-1]-hash[i])){
                ans++;
            }
        }
        return ans;
        
    }
};