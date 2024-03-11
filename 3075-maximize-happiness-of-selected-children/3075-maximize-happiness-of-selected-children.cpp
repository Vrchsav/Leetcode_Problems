class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long count =0;
        sort(happiness.begin(),happiness.end());
        long long ans=0;
        for(int i=happiness.size()-1;i>=0;i--){
            if(k==0){
                break;
            }
            if(happiness[i]-count>0){
            ans+=happiness[i]-count;
            count++;
            k--;
                }
            else{
                break;
            }
        }

        return ans;
    }
};