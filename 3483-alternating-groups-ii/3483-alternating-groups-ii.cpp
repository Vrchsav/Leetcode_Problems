class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ans = 0;
        int siz = colors.size();
        int j = 0;

        for (int i = 1; i < 2 * siz; i++) { // Simulate circular array for 2 cycles
            if (colors[(i - 1) % siz] == colors[i % siz]) {
                j = i; // Reset start of alternating sequence
            }

            if (i - j + 1 == k) { 
                ans++; 
                j = i; // Move past the found sequence
            }
        }

        return ans;
    }
};
