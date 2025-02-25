class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        set<int>stt;
 int ans=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            count+=nums[i];
            nums[i]=count;
            if(stt.find(nums[i]-k)!=stt.end()){
                ans++;
            }
            if(nums[i]==k){
                ans++;
            }
            stt.insert(count);
        }
       
    
        return ans;

        
    }
};