class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& interval) {
        vector<vector<int>> ans;
        ans.push_back(interval[0]);
        sort(interval.begin(), interval.end());
        for(int i=1;i<interval.size();i++){
            if(interval[i][0]<=ans.back()[1]){
                ans.back()[1]=max(ans.back()[1],interval[i][1]);
            }else{
        ans.push_back(interval[i]);

            }
        }
        return ans;
    }
};