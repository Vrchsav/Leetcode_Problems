class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        vector<vector<int>>vcc;
        for(auto &a:intervals){
            vcc.push_back({a[0],1});
            vcc.push_back({a[1],-1});

        }
        sort(vcc.begin(), vcc.end(), [](vector<int> &a, vector<int> &b) {
    if (a[0] == b[0]) {
        return a[1] > b[1]; // Sort by second element in descending order if first elements are equal
    }
    return a[0] < b[0]; 
});

        int start=-1;
        int end=-1;
        int total=0;
        for(auto &a:vcc){
            if(total==0 ){
                start=a[0];
                total+=a[1];
            }else{
                total+=a[1];
                if(total==0){
                    end=a[0];
                    ans.push_back({start,end});
                }
            }

        }
        return ans;

    }
};