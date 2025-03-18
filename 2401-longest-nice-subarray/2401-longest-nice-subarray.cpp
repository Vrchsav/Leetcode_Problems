class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int j = 0;
        int c = -1;
      
        int orr = nums[0];
        for (int i = 0; i < nums.size(); i++) {

            if ((nums[i] & orr) == 0) {
                orr = orr | nums[i];
               
            } else {
                while (j<i) {
                    orr = orr ^ nums[j];
                    j++;
                    if ((nums[i] & orr) == 0) {
                        orr = orr | nums[i];
                        break;
                        
                    }

                }
               
            }
            c = max(i-j+1, c);
        }
        return c;
    }
};