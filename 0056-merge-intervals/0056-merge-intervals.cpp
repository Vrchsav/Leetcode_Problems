class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        int i=0;
        while(i<intervals.size()){
            int s=intervals[i][0];
            int e=intervals[i][1];
            if(s==e){
            ans.push_back({s,e});
                i++;
                continue;
            }
            while(i<intervals.size() &&e >=intervals[i][0]  ){
                
                s=(min(s,intervals[i][0]));
                e=max(e,intervals[i][1]);
                i++;
            }
            ans.push_back({s,e});
            
        } 
        return ans;
    }
};