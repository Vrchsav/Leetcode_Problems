class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mpp;
        vector<int>ans;
        for(auto a:nums){
            if(mpp.find(a)==mpp.end()){
                mpp[a]=1;
            }
            else{
                mpp[a]++;
            }
        }
        map<int, int>::iterator it = mpp.begin();
        priority_queue<pair<int,int>>q;
        while (it != mpp.end()) {
        q.push({it->second,it->first});
        ++it;
    }
        while(!q.empty() && ans.size()!=k){
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};