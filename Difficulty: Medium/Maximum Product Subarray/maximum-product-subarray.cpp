//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        int ans=arr[0];
        int counter=1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0){
                ans=max(ans,counter);
                counter=1;
            }
            else{
                counter*=arr[i];
                ans=max(ans,counter);
            }
        }
        counter=1;
        for(int i=arr.size()-1;i>=0;i--){
            if(arr[i]==0){
                ans=max(ans,counter);
                counter=1;
            }
            else{
                counter*=arr[i];
                ans=max(ans,counter);
            }
        }
        return ans;
        // Your Code Here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends