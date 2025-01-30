class Solution {
void solve(int open, int close, string str, vector<string>&ans) {
    if (open == 0 && close == 0) {
        ans.push_back(str);
        return;
    }

    if (open > 0) {
        solve(open - 1, close, str + '(',ans);
    }

    if (close > open) {
        solve(open, close - 1, str + ')',ans);
    }
}
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(n,n,"",ans);
        return ans;
    }
};