class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>>ans;
        for(int i=0;i<nums.size();i++){
            string stt=to_string(nums[i]);
            string d;
            for(auto c:stt){
                int g=c-'0';
                d+=to_string(mapping[g]);

            }
            ans.push_back({stoi(d),i});
            d="";
        }
        sort(ans.begin(),ans.end());
        vector<int>a;
        for(auto f:ans){
            a.push_back(nums[f.second]);
        }
        return a;
    }
};