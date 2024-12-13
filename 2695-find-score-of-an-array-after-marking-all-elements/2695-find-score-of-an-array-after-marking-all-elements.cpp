class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long ans =0;
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        for(int i=0;i<nums.size();i++){
            q.push({nums[i],i});
        }


        while(!q.empty()){
            auto [value,index]=q.top();
            q.pop();
            if(nums[index]!=-1){
                ans+=value;
                nums[index]=-1;
                if(index-1>=0){
                    nums[index-1]=-1;
                }
                if(index+1<nums.size()){
                    nums[index+1]=-1;
                }

            }
        }
        return ans;
        

        
    }
};