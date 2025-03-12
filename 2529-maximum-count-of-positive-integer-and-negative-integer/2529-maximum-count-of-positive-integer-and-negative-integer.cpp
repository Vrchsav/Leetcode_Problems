class Solution {
public:
    int maximumCount(vector<int>& nums) {


        auto lambdaP=[](int nums){
            return nums>0;
        };
        auto lambdaN=[](int nums){
            return nums<0;
        };
        int positive= count_if(nums.begin(),nums.end(),lambdaP);
        int negative= count_if(nums.begin(),nums.end(),lambdaN);

        return max(positive,negative);

        
    }
};