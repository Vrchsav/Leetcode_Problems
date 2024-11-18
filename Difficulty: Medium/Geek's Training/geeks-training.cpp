//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    int solve(vector<vector<int>>& arr, int n,int current,vector<vector<int>>&dp){
        if(n<0){
            return 0;
        }
        if (current == -1) {
        return max(
            solve(arr, n - 1, 0, dp) + arr[n][0],
            max(
                solve(arr, n - 1, 1, dp) + arr[n][1],
                solve(arr, n - 1, 2, dp) + arr[n][2]
            )
        );
    }
        if(dp[n][current]!=-1){
            return dp[n][current];
        }
        int a = 0, b = 0, c = 0;

        if(current==-1 || current !=0){
         a=solve(arr,n-1,0,dp)+arr[n][0];}
        if(current==-1 || current !=1){
         b=solve(arr,n-1,1,dp)+arr[n][1];}
        if(current==-1 || current !=2){
         c=solve(arr,n-1,2,dp)+arr[n][2];}
         
        dp[n][current]=max(a,max(b,c));
        return dp[n][current];


        
    }
  public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return solve(arr,n-1,-1,dp);
        // Code here
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends