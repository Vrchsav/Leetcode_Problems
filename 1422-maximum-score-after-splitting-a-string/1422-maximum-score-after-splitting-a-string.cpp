class Solution {
public:
    int maxScore(string s) {
        int zero = 0;
        int ans = -1;
        int one = 0;
        for (int i = 0; i < s.size(); i++) {
            if(s[i]=='1'){
                one++;
            }
        }

        for (int i = 0; i < s.size()-1; i++) {
            if (s[i] == '0') {
                zero++;
            } else {
                one--;
            }
            ans = max(ans, zero+one);
        }
        return ans;
    }
};