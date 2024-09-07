class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum=0;
        int k=rolls.size();
        for(auto a:rolls){
            sum+=a;
        }
        int x=(n+k)*mean-sum;
        if(x < n || x >(n*6)){
            return {};
        }
        int rem=x%n;
        int quo=x/n;
        vector<int>ans(n,quo);
        if(rem>0){
        for(int i=0 ;i<n;i++){
            ans[i]++;
            rem--;
            if(rem==0){
                break;
            }
        }}
        return ans;
    }
};