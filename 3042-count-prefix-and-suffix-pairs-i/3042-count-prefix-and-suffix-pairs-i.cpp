class Solution {
    bool isPrefixAndSuffix(string a, string b) {
        int n = a.size();
        int m = b.size();
        if (m >= n && b.substr(0, n) == a && b.substr(m - n, n)==a) {
            return true;
        }
        return false;
    }

public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    ans++;
                }
            }
        }
        return ans;
    }
};