//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        unordered_map<int,bool>mpp;
        stack<int>stt;
        stt.push(0);
        vector<int>ans;
        while(!stt.empty()){
            int front=stt.top();
            stt.pop();
            if (!mpp[front]) {
                mpp[front] = true;
                ans.push_back(front);}
            for(int i=adj[front].size()-1;i>=0;i--){
                int a=adj[front][i];
                if(!mpp[a]){
                    stt.push(a);
                }
            }
            
        }
        return ans;
        // Code here
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends