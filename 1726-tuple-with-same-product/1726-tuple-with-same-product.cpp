class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                mpp[nums[i]*nums[j]]++;
                

            }
        }
        int ans=0;
        for(auto it=mpp.begin();it!=mpp.end();it++){
            int count = it->second;
            if(count > 1) {
                ans += (count * (count - 1)) / 2 * 8;
            }
        }

        
        return ans;
    }
};