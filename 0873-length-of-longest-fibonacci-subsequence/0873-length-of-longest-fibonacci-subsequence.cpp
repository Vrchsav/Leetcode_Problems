class Solution {

    // int solve(vector<int>& arr, int index, int prev, map<int, int>& mpp) {
    //     if (index >= arr.size()) {
    //         return 0;
    //     }

    //     int a = 0;
    //     if (prev != -1 && mpp.find(prev + arr[index]) != mpp.end()) {
    //         a = 1 + solve(arr, mpp[prev + arr[index]], arr[index], mpp);
    //     }
    //     if (prev == -1){
    //         a = 1 + solve(arr, index + 1, arr[index], mpp);}

    //     int b = solve(arr, index + 1, prev, mpp);

    //     return max(a, b);
    // }

    int solve(int i,int j,vector<int>&arr,map<int, int>& mpp){
       
        if(mpp.find(arr[i]-arr[j])!=mpp.end() && mpp[arr[i]-arr[j]]<j){
            return 1+solve(j,mpp[arr[i]-arr[j]],arr,mpp);
        }
        return 2;
    };

public:
    int lenLongestFibSubseq(vector<int>& arr) {

        map<int, int> mpp;
        for (int i = 0; i < arr.size(); i++) {
            mpp[arr[i]] = i;
        }

        int ans=0;
        for(int i=1;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                int t=solve(j,i,arr,mpp);
                if(t>=3)
                ans=max(ans,t);
            }
        }






        return ans ;
    }
};