class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int m) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;
        for(int i=0;i< nums.size();i++){
            q.push({nums[i],i});
        }

        while(k>0){
            pair<int,int>top=q.top();
            q.pop();
            q.push({top.first*m,top.second});
            k--;
        }

        vector<int>ans(nums.size());
        while(!q.empty()){
            pair<int,int>top=q.top();
            q.pop();
            ans[top.second]=top.first;
        }
        return ans;
        
    }
};