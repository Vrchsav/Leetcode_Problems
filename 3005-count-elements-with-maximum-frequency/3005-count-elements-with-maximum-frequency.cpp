class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int>mapp;
        for(int i=0;i<nums.size();i++){
            mapp[nums[i]]++;
        }
        auto it=mapp.begin();
        int maxx=0;
        
        while(it!=mapp.end()){
            maxx=max(it->second,maxx);
            it++;
        }
        cout<<maxx;
        it=mapp.begin();
        int ans=0;
        while(it!=mapp.end()){
            if(it->second == maxx){
                ans+=maxx;
            }
            it++;
        }
        return ans;
        
    }
};