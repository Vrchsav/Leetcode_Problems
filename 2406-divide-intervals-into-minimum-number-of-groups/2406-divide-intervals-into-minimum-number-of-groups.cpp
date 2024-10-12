class Solution {
public:
    static bool customComparison(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];  // If start times are the same, compare by end times
        }
        return a[0] < b[0];  // Otherwise, compare by start times
    }

    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), customComparison);
        priority_queue<int,vector<int>,greater<int>>q;
        for(int i=0;i<intervals.size();i++){
            if(q.empty()){
                q.push(intervals[i][1]);
            }
            else{
                if(q.top()<intervals[i][0]){
                    q.pop();

                }
                q.push(intervals[i][1]);

            }
        }
        return q.size();  
    }
};
