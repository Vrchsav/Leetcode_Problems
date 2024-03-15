class Solution {
public:
    vector<int> productExceptSelf(vector<int> nums) {
        int mul = 1;
        int flag = 0;
        for (auto a : nums) {
            if (a != 0)
                mul *= a;
            else
                flag++;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                if (flag == 0) {
                    nums[i] = mul / nums[i];
                } else {
                    nums[i] = 0;
                }
            } else {
                if (flag == 1) {
                    nums[i] = mul;
                } else {
                    nums[i] = 0;
                }
            }
        }
        return nums;
    }
};