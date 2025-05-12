class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {

        vector<int> vcc(10, 0);
        for (int a : digits) {
            vcc[a]++;
        }
        vector<int> ans;
        for (int i = 1; i <= 9; i++) {
            if (vcc[i] == 0)
                continue;
            vcc[i]--;
            for (int j = 0; j <= 9; j++) {
                if (vcc[j] == 0)
                    continue;
                vcc[j]--;
                for (int k = 0; k <= 8; k += 2) {
                    if (vcc[k] == 0)
                        continue;
                    vcc[k]--;
                    int num = i * 100 + j * 10 + k;
                    ans.push_back(num);
                    vcc[k]++;
                }
                vcc[j]++;
            }
            vcc[i]++;
        }

        return ans;
    }
};