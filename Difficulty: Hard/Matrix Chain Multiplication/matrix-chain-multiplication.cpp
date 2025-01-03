//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
     int solve(int i,int j,vector<int>&arr ,  vector<vector<int>>&dp){
         if(i==j){
             return 0;
         }
         if(dp[i][j]!=-1){
             return dp[i][j];
         }
         int ans=INT_MAX;
         for(int k=i;k<j;k++){
             
             int n=arr[i-1]*arr[k]*arr[j]+solve(i,k,arr,dp)+solve(k+1,j,arr,dp);
            ans=min(ans,n);
            
             
             
         }
         return dp[i][j]=ans;
     }
  public:
    int matrixMultiplication(vector<int> &arr) {
        int n=arr.size();
        // code here
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans=solve(1,n-1,arr,dp);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.matrixMultiplication(a) << endl << "~\n";
    }

    return 0;
}

// } Driver Code Ends