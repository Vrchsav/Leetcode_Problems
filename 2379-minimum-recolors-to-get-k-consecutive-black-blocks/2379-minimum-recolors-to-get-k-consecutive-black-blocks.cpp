class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int white = 0, ans = INT_MAX;

        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') white++;
        }

        ans = white;  

        for (int i = k; i < blocks.size(); i++) {
            if (blocks[i] == 'W') white++;     
            if (blocks[i - k] == 'W') white--;
            ans = min(ans, white);            
        }

        return ans;
    }
};
