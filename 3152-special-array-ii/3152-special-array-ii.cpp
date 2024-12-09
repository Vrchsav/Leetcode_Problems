class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        int n = nums.size();
      vector<int> hash(n + 1, 1);  
        for (int i = 1; i < n; i++) {
            if ((nums[i] & 1) != (nums[i - 1] & 1)) {
                hash[i] = hash[i - 1] + 1;
            }
        }
        vector<bool> ans;
        for (int i = 0; i < queries.size(); i++) {
            int total_ele = queries[i][1] - queries[i][0];
            if (total_ele == 1) {
                if ((nums[queries[i][1]] & 1) != (nums[queries[i][0]] & 1)) {
                    ans.push_back(true);
                } else {
                    ans.push_back(false);
                }

            } 
             else if (total_ele >= hash[queries[i][1]]) {
                ans.push_back(false);
                cout<<hash[queries[i][1]];
            } else {
                ans.push_back(true);
            }
        }
        return ans;
    }
};