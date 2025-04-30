class Solution {
public:
    int findNumbers(vector<int>& nums) {
int ans=0;
        for(int a:nums){
            string to_str=to_string(a);
            if(to_str.size()%2==0){
                ans++;
            }
        }
        return ans;
    }
};