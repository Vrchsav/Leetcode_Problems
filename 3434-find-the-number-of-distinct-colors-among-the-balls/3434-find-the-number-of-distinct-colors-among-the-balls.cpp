class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> ans;
        map<int, int> arr;
        map<int,int> colour;
        for (int i = 0; i < queries.size(); i++) {
            int key = queries[i][0];
            int value = queries[i][1];

            if (arr.find(key) != arr.end()) {
                colour[arr[key]]--;
                if(colour[arr[key]]<=0){
                    colour.erase(arr[key]);
                }
            }

            arr[key] = value;
            colour[value]++;

            ans.push_back(colour.size()); 
        }

        return ans;
    }
};