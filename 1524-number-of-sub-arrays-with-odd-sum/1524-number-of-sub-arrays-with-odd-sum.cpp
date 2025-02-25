class Solution {
   
public:
    static constexpr int MOD = 1000000007;
    int numOfSubarrays(vector<int>& arr) {
        for(int i=1;i<arr.size();i++){
            arr[i]=arr[i]+arr[i-1];
        }


        int evencount=1;
        int oddcount=0;

        int ans=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]%2!=0){
                ans+=(evencount)  ;
                ans=ans %MOD;
                oddcount++;
            }
            else{
                evencount++;
                ans+=(oddcount %MOD) %MOD;
                ans=ans %MOD;


            }
        }
        return ans;
    }
};