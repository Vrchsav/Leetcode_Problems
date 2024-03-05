class Solution {
public:
    int minimumLength(string s) {

        int j = s.size() - 1;

        int i = 0;

        int ele;
        while (i < j) {
            ele = s[i];
            if (ele == s[j]) {
                i++;
                j--;
            } else {
                break;
            }
            while (s[i] == ele) {

                i++;
            }
            if (i >= j) {
                break;
            }
            while (s[j] == ele) {

                j--;
            }
        }
        if (j - i + 1 <= 0) {
            return 0;
        }
        return j - i + 1;
    }
};