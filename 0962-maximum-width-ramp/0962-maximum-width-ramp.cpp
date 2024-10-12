class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        priority_queue<pair<int,int>>q;
        stack<pair<int,int>>stt;
        stt.push({nums[nums.size()-1],nums.size()-1});
        for(int i=nums.size()-2;i>=0;i--){
                if(stt.top().first<nums[i]){
                    stt.push({nums[i],i});
                    }
        }
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            int d=nums[i];
            pair<int,int>temp={2,i};
            while(!stt.empty() && stt.top().first>=d){
                temp=stt.top();
                cout<<temp.first<<" ";
                stt.pop();
            }
            cout<<endl;
            ans=max(ans,(temp.second-i));
        }
        return ans;

    }
};