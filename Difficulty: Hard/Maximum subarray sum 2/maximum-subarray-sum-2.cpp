#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxSubarrSum(vector<int>& arr, int a, int b) {
        int n = arr.size();
        vector<long long> prefix(n+1, 0);
        for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + arr[i];
        
        multiset<long long> window;
        long long ans = LLONG_MIN;
        
        for (int r = a; r <= n; r++) {
            window.insert(prefix[r-a]);
            if (r - b - 1 >= 0) {
                window.erase(window.find(prefix[r-b-1]));
            }
            ans = max(ans, prefix[r] - *window.begin());
        }
        
        return (int)ans;
    }
};
