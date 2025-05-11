class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int c = 0;
        for (auto a : arr) {
            if (a % 2 != 0) {
                c++;
                if (c >= 3) {
                    return true;
                }
            } else {
                c = 0;
            }
        }
        if (c >= 3) {
            return true;
        }
        return false;
    }
};