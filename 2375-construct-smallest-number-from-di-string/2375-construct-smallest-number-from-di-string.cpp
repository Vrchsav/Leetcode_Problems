class Solution {

    bool solve(string pattern, vector<string>& ans, vector<int>& visited,
               int pos) {
        if(pos>=ans.size()){
            return true;
        }

        for (int i = 1; i <= 9; i++) {
            if (visited[i] == 0) {
                if (pos == 0) {
                    ans[pos] = to_string(i);
                    visited[i] = 1;
                    if (solve(pattern, ans, visited, pos + 1))
                        return true;
                    visited[i] = 0;
                } else {
                    int prev_num = stoi(ans[pos - 1]);
                    if (pattern[pos - 1] == 'I') {
                        for (int k = prev_num + 1; k <= 9; k++) {
                            if (visited[k] == 0) {
                                ans[pos] = to_string(k);
                                visited[k] = 1;
                                if (solve(pattern, ans, visited, pos + 1))
                                    return true;
                                visited[k] = 0;
                            }
                        }
                    } else {
                        for (int k = 1; k < prev_num; k++) {
                            if (visited[k] == 0) {
                                ans[pos] = to_string(k);
                                visited[k] = 1;
                                if (solve(pattern, ans, visited, pos + 1))
                                    return true;
                                visited[k] = 0;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }

public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        vector<string> ans(n + 1);
         vector<int> visited(10, 0);
        bool temp = solve(pattern, ans, visited, 0);
        string a="";
        for(int i=0;i<ans.size();i++){
            a+=ans[i];
        }
        return a;
    }
};