class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ans = 0;

        for (int i = 0; i < k - 1; i++) {
            colors.push_back(colors[i]);
        }
        int siz = colors.size();
        int j = 0;
        int i;
        for (i = 1; i < siz; i++) {
            if (colors[i - 1] == colors[i]) {
                j = i;
            }
            if (i - j + 1 == k) {
                ans++;
                j++;
               
            }
        }
        
        return ans;
    }
};