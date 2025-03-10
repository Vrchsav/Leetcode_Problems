class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ans = 0;

        int siz = colors.size();
        int j = 0;
        int i=1;
        while (j<siz) {
            if (colors[(i - 1)%siz] == colors[i%siz]) {
                j = i;
            }
            if (i - j + 1 == k) {
                ans++;
                j++;
               
            }
            i++;
        }
        
        return ans;
    }
};